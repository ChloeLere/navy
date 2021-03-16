/*
** EPITECH PROJECT, 2021
** display
** File description:
** display map + begin game
*/

#include "lib/my/my.h"

void display_map(char **map)
{
    char **map_vide = create_map();

    my_printf("my positions:\n");
    draw_map(map);
    my_printf("enemy's positions:\n");
    draw_map(map_vide);
}

void draw_map(char **map)
{
    int x = 0;
    int y = 0;
    int temp = 0;

    display_2_first_line();
    for (; x < 8; x++) {
        for (y = 0, temp = 0; temp <= 19; temp++) {
            if (map[x][y] == '\0') {
                my_putchar('\n');
                y++;
            } else
                y = draw_map_part_2(map[x][y], temp, y);
        }
    }
}

int draw_map_part_2(char map, int temp, int y)
{
    if (map != '\0' && (temp % 2) > 0 && y > 2) {
        my_putchar(' ');
    }
    if (map != '\0' && (temp % 2) == 0) {
        my_putchar(map);
        y++;
    }
    return (y);
}

void display_2_first_line(void)
{
    my_putchar(' ');
    my_putchar(124);
    my_printf("A B C D E F G H\n");
    my_putchar('-');
    my_putchar(43);
    for (int i = 0; i < 15; i++)
        my_putchar('-');
    my_putchar('\n');
}