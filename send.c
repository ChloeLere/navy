/*
** EPITECH PROJECT, 2021
** send
** File description:
** fonction for send co
*/

#include "lib/my/my.h"

int *send(char *mess, int pid)
{
    mess = check_nbr_alpha(mess);
    int x = (mess[1] - '0');
    char *binary_x = convert_to_binary_char(x);
    char *binary_y = NULL;
    int *co = malloc(sizeof(int) * 2);
    co[1] = x;
    co[2] = (mess[0] - 'A') + 1;
    for (x = 0; x < 4; x++) {
        if (binary_x[x] == '0')
            kill(pid, SIGUSR1);
        if (binary_x[x] == '1')
            kill(pid, SIGUSR2);
        usleep(10000);
    }
    binary_y = send_y(mess, pid);
    free(binary_x);
    free(binary_y);
    return (co);
}

char *send_y(char *mess, int pid)
{
    int x = 0;
    int y = (mess[0] - 'A') + 1;
    char *binary_y = convert_to_binary_char(y);

    for (x = 0; x < 4; x++) {
        if (binary_y[x] == '0')
            kill(pid, SIGUSR1);
        if (binary_y[x] == '1')
            kill(pid, SIGUSR2);
        usleep(10000);
    }
    return (binary_y);
}

char *convert_to_binary_char(int nbr)
{
    char *binary = malloc(sizeof(char) * 4);
    int c = 3;

    for (; c >= 0; c--, nbr /= 2) {
        if (nbr < 0) {
            binary[c] = '0';
            break;
        }
        binary[c] = (nbr % 2) + '0';
    }
    binary[4] = '\0';
    return (binary);
}

char *check_nbr_alpha(char *str)
{
    str[0] = lower_alpha(str[0]);
    if (!((str[0] >= 'A' && str[0] <= 'H')))
            str[0] = 'A';
    if (!(str[1] >= '1' && str[1] <= '8'))
            str[1] = '1';
    return (str);
}

char lower_alpha(char s)
{
    if (s >= 'a' && s <= 'z')
        s -= ('a' - 'A');
    return (s);
}
