/*
** EPITECH PROJECT, 2021
** player1
** File description:
** handling player 1
*/

#include "lib/my/my.h"

info_t data = {0, NULL, 0, NULL, 0, 0};

void hdlr(int sig)
{
    if (sig == 10) {
        my_printf(": missed\n");
    }
    if (sig == 12) {
        my_printf(": hit\n");
    }
    data.res = sig;
}

void action(int sig, siginfo_t *i, void *ucontext)
{
    data.pid = i->si_pid;
    if (data.loop == 0) {
        my_printf("enemy connected\n");
        data.loop = 1;
        return;
    }
    if (sig == 10)
        my_printf(": missed\n");
    if (sig == 12)
        my_printf(": hit\n");
    data.res = sig;
}

void s1(int sig, siginfo_t *i, void *ucontext)
{
    if (sig == 10) {
        data.b[data.c] = '1';
        data.c++;
    }
    if (sig == 12) {
        data.b[data.c] = '2';
        data.c++;
    }
}

void first_tour_p1(char *file_path)
{
    data.b = malloc(sizeof(char) * 9);
    gnl_t d = create_struct_p1(data, file_path);
    statu_game_t sg = init_struc();
    while (sg->nbr_t_other < 14 && sg->nbr_touch < 14) {
        data.co = send(d->gmessage, data.pid);
        pause();
        d->gmap_en = find_if_touch(sg, data.res, d->gmap_en, data.co);
        my_printf("waiting for enemy's attack...\n");
        reception();
        if (data.c == 7)
            data.b[7] = '\0';
        data.co = convert_to_co(data.b);
        if (next_p1(data, d, sg) < 0)
            return;
        data.c = 0;
    }
    end_game(sg, d->gmy_map, data.co);
}

void first_tour_p2(char *file_path, int pid_other)
{
    statu_game_t sg = init_struc();
    gnl_t g = create_struct_p2(data, file_path, pid_other);
    data.b = malloc(sizeof(char) * 9);
    while (sg->nbr_t_other < 14 && sg->nbr_touch < 14) {
        reception();
        if (data.c == 7)
            data.b[7] = '\0';
        data.co = convert_to_co(data.b);
        g->gmy_map = said_if_touch(sg, pid_other, g->gmy_map, data.co);
        my_printf("attack: ");
        g->gmessage = get_new_mess();
        data.co = send(g->gmessage, pid_other);
        pause();
        g->gmap_en = find_if_touch(sg, data.res, g->gmap_en, data.co);
        if (next_p2(data, g, sg) < 0)
            return;
        data.c = 0;
    }
    end_game(sg, g->gmy_map, data.co);
}