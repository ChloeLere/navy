/*
** EPITECH PROJECT, 2021
** new_attack
** File description:
** get new message
*/

#include "lib/my/my.h"

char *get_new_mess(void)
{
    char *buf = malloc(sizeof(char) * 4);
    int t = read(0, buf, sizeof(buf));

    if (t == -1) {
        write (2, "Error, default value taken : A1", 32);
        return ("A1");
    }
    if (t == 0)
        kill(getpid(), SIGINT);
    buf = check_size(buf);
    write (1, buf, 2);
    return (buf);
}