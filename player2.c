/*
** EPITECH PROJECT, 2021
** player2
** File description:
** handling player 2
*/

#include "lib/my/my.h"

void display_all_map(char **my_map, char **map_enemy)
{
    my_printf("my positions:\n");
    draw_map(my_map);
    my_printf("enemy's positions:\n");
    draw_map(map_enemy);
}

int next_p1(info_t data, gnl_t d, statu_game_t sg)
{
    d->gmy_map = said_if_touch(sg, data.pid, d->gmy_map, data.co);
    display_all_map(d->gmy_map, d->gmap_en);
    if (sg->nbr_t_other >= 14 || sg->nbr_touch >= 14) {
        end_game(sg, d->gmy_map, data.co);
        return (-1);
    }
    my_printf("attack: ");
    d->gmessage = get_new_mess();
    return (0);
}

int next_p2(info_t data, gnl_t g, statu_game_t sg)
{
    display_all_map(g->gmy_map, g->gmap_en);
    if (sg->nbr_t_other >= 14 || sg->nbr_touch >= 14) {
        end_game(sg, g->gmy_map, data.co);
        return (-1);
    }
    my_printf("waiting for enemy's attack...\n");
    return (0);
}