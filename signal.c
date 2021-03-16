/*
** EPITECH PROJECT, 2021
** signal
** File description:
** handling signal
*/

#include "lib/my/my.h"

void fsp1_part2(char **map)
{
    struct sigaction siga;

    siga.sa_flags = SA_SIGINFO;
    siga.sa_handler = action;
    my_printf("waiting for enemy connection...\n");
    sigaction(SIGUSR1, &siga, NULL);
    sigaction(SIGUSR2, &siga, NULL);
    pause();
    display_map(map);
    my_printf("attack: ");
}

char *first_signal_p1(char **map)
{
    char *buf = malloc(sizeof(char) * 4);
    int t = 0;

    fsp1_part2(map);
    t = read(0, buf, sizeof(buf));
    if (t == -1) {
        write (2, "\nError, default value taken : A1", 33);
        return ("A1");
    }
    if (t == 0)
        kill(getpid(), SIGINT);
    buf = check_size(buf);
    write (1, buf, 2);
    return (buf);
}

void first_signal_p2(int pid, char **map)
{
    my_printf("successfully connected\n");
    kill(pid, SIGUSR1);
    usleep(10000);
    display_map(map);
    my_printf("waiting for enemy's attack...\n");
}

char *check_size(char *buf)
{
    if (my_strlen(buf) < 3) {
        if (buf[0] == '\n')
            buf[0] = 'A';
        buf[1] = '1';
        buf[2] = '\n';
    }
    return (buf);
}