/*
** EPITECH PROJECT, 2021
** main_navy
** File description:
** main of navy
*/

#include "lib/my/my.h"

int display_h(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_printf("USAGE\n");
        my_printf("     ./navy");
        my_printf(" [first_player_pid]");
        my_printf(" navy_positions\n");
        my_printf("DESCRIPTION\n");
        my_printf("     first_player_pid: only for the 2nd player. ");
        my_printf("pid of the first player.\n");
        my_printf("     navy_positions: file representing the ");
        my_printf("positions of the ships.\n");
        return (1);
    }
    return (0);
}

int error_handling(int argc, char **argv)
{
    if (argc <= 1 || argc > 3) {
        my_putstr_error("Error : not enough / too many arguments\n");
        return (84);
    }
    if (argv[1][0] == '-' && argv[1][1] != 'h') {
        my_putstr_error("Error : wrong argument\n");
        return (84);
    }
    return (0);
}

int error_hl_file(int argc, char **argv)
{
    if (argc == 2) {
        if (open_file_int(argv[1]) == 84) {
            my_putstr_error("Error\n");
            return (84);
        }
    } else {
        if (open_file_int(argv[2]) == 84) {
            my_putstr_error("Error\n");
            return (84);
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (error_handling(argc, argv) == 84)
        return (84);
    if (display_h(argv) == 1)
        return (0);
    if (error_hl_file(argc, argv) == 84)
        return (84);
    if (argc == 2) {
        first_tour_p1(argv[1]);
    }
    if (argc == 3) {
        first_tour_p2(argv[2], my_getnbr_with_i(argv[1], 0));
    }
    return (0);
}
