/*
** EPITECH PROJECT, 2021
** touch_or_not
** File description:
** find if touch a boat or not
*/

#include "lib/my/my.h"

char **said_if_touch(statu_game_t sg, int pid_other, char **my_map, int *co)
{
    usleep(50000);
    if (my_map[co[1]][co[2] + 2] == '.' || my_map[co[1]][co[2] + 2] == 'o') {
        kill(pid_other, SIGUSR1);
        my_map[co[1]][co[2] + 2] = 'o';
    }
    if ((my_map[co[1]][co[2] + 2] >= '0' && my_map[co[1]][co[2] + 2] <= '9')
    || my_map[co[1]][co[2] + 2] == 'x') {
        kill(pid_other, SIGUSR2);
        if (my_map[co[1]][co[2] + 2] >= '0'
        && my_map[co[1]][co[2] + 2] <= '9')
            sg->nbr_touch += 1;
        my_map[co[1]][co[2] + 2] = 'x';
    }
    struct sigaction st;
    st.sa_flags = SA_SIGINFO;
    st.sa_handler = hdlr;
    sigaction(SIGUSR1, &st, NULL);
    sigaction(SIGUSR2, &st, NULL);
    return (my_map);
}

char **find_if_touch(statu_game_t sg, int sig, char **map, int *co)
{
    if (sig == 10) {
        map[co[1] - 1][co[2] + 1] = 'o';
    }
    if (sig == 12) {
        if (map[co[1] - 1][co[2] + 1] == '.')
            sg->nbr_t_other += 1;
        map[co[1] - 1][co[2] + 1] = 'x';
    }
    return (map);
}