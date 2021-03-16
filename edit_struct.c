/*
** EPITECH PROJECT, 2021
** edit_struct
** File description:
** create & edit struct
*/

#include "lib/my/my.h"

gnl_t create_struct_p1(info_t data, char *file_path)
{
    gnl_t d = malloc(sizeof(*d));

    my_printf("my_pid: %d\n", getpid());
    d->gpid = data.pid;
    d->gco = data.co;
    d->gc = data.c;
    d->gb = data.b;
    d->gloop = data.loop;
    d->gres = data.res;
    d->gmy_map = get_map(open_file(file_path, "Error"));
    d->gmessage = first_signal_p1(d->gmy_map);
    d->gmap_en = create_map();
    return (d);
}

gnl_t create_struct_p2(info_t data, char *file_path, int pid_other)
{
    gnl_t d = malloc(sizeof(*d));
    d->gpid = data.pid;
    d->gco = data.co;
    d->gc = data.c;
    d->gb = data.b;
    d->gloop = data.loop;
    d->gres = data.res;
    d->gmy_map = get_map(open_file(file_path, "Error"));
    d->gmap_en = create_map();
    d->gmessage = NULL;
    my_printf("my_pid: %d\n", getpid());
    first_signal_p2(pid_other, d->gmy_map);
    return (d);
}

void end_game(statu_game_t sg, char **my_map, int *co)
{
    win_or_lose(sg);
    free_map(my_map);
    free(co);
}