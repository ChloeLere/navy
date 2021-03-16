/*
** EPITECH PROJECT, 2021
** handling_map
** File description:
** create & edit map
*/

#include "lib/my/my.h"

char **create_map(void)
{
    char **map = malloc(sizeof(char *) * (20));
    int x = 0;
    int y = 0;
    int c = 0;

    for (x = 0; 8 > x; x++, c++) {
        map[x] = malloc(sizeof(char) * (20));
        for (y = 0; 9 >= y; y++) {
            map[x][y] = set_map(map, x, y, c);
        }
        map[x][y + 1] = '\0';
    }
    return (map);
}

void free_map(char **map)
{
    for (int x = 0; x < 8; x++)
        free(map[x]);
    free(map);
}

char set_map(char **map, int x, int y, int c)
{
    if (y == 0)
        map[x][y] = '1' + c;
    if (y == 1)
        map[x][y] = '|';
    if (y > 1)
        map[x][y] = '.';
    if (y == 10)
        map[x][y] = '\0';
    return (map[x][y]);
}