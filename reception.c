/*
** EPITECH PROJECT, 2021
** reception
** File description:
** resception co attack
*/

#include "lib/my/my.h"

void reception(void)
{
    struct sigaction s;

    s.sa_flags = SA_SIGINFO;
    s.sa_handler = s1;
    reception_sig(s);
    for (int x = 0; x < 8; x++)
        pause();
}

void reception_sig(struct sigaction s)
{
    sigaction(SIGUSR1, &s, NULL);
    sigaction(SIGUSR2, &s, NULL);
}