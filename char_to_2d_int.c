/*
** EPITECH PROJECT, 2021
** char_to_2d_int
** File description:
** convert char * to int **
*/

#include "lib/my/my.h"

int **malloc_co(void)
{
    int **co = malloc(sizeof(int *) + 3);
    int x = 0;

    for (; x < 3; x++)
        co[x] = malloc(sizeof(int) * 8);
    co[3] = '\0';
    co[1][9] = '\0';
    co[2][9] = '\0';
    return (co);
}

int **char_to_2d_int(char *coordo)
{
    int **co = malloc_co();
    int x = 1;
    int y = 1;
    int i = 1;

    for (x = 1; coordo[x] != '\0'; x++) {
        if (coordo[x] >= 'A' && coordo[x] <= 'H') {
            co[2][y] = coordo[x] - 'A';
            y++;
        }
        if (coordo[x] >= '0' && coordo[x] <= '8' && coordo[x - 1] != '\n') {
            co[1][i] = my_getnbr_with_i(coordo, x);
            i++;
        }
    }
    return (co);
}