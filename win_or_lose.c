/*
** EPITECH PROJECT, 2021
** win_or_lose
** File description:
** find if player win or lose
*/

#include "lib/my/my.h"

void win_or_lose(statu_game_t sg)
{
    if (sg->nbr_t_other == 14)
        my_printf("I won\n");
    if (sg->nbr_touch == 14)
        my_printf("Enemy won\n");
}