/*
** EPITECH PROJECT, 2021
** statu_game
** File description:
** define if lose or win
*/

#include "lib/my/my.h"

statu_game_t init_struc(void)
{
    statu_game_t sg = malloc(sizeof(statu_game_t));

    sg->lose = 0;
    sg->win = 0;
    sg->nbr_touch = 0;
    sg->nbr_t_other = 0;
    return (sg);
}