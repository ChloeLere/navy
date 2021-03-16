/*
** EPITECH PROJECT, 2021
** edit_map
** File description:
** edit map
*/

#include "lib/my/my.h"

char **edit_map(char *coordo, char **map)
{
    int **co = char_to_2d_int(coordo);
    int c = 2;
    int t = 1;

    for (; c <= 5; c++, t += 2) {
        if (co[1][t] == co[1][t + 1])
            map = edit_map_colone(map, co, c, t);
        if (co[2][t] == co[2][t + 1])
            map = edit_map_line(map, co, c, t);
    }
    return (map);
}

char **edit_map_line(char **map, int **co, int c, int t)
{
    int x = co[1][t] - 1;
    int y = co[2][t] + 2;
    int temp = x + c;

    for (; x < temp; x++)
        map[x][y] = c + '0';
    return (map);
}

char **edit_map_colone(char **map, int **co, int c, int t)
{
    int x = co[1][t] - 1;
    int y = co[2][t] + 2;
    int temp = y + c;

    for (; y < temp; y++)
        map[x][y] = c + '0';
    return (map);
}

char **get_map(char *co)
{
    char **map = edit_map(co, create_map());

    return (map);
}