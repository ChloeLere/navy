/*
** EPITECH PROJECT, 2021
** convertion_navy
** File description:
** convert
*/

#include "lib/my/my.h"

int *convert_to_co(char *binary)
{
    int *co = malloc(sizeof(int) * 2);

    co[1] = my_getnbr_stop(binary, 0, 3);
    co[2] = my_getnbr_with_i(binary, 4);
    co[1] = convert_n(co[1], "123456789", 8);
    co[2] = convert_n(co[2], "123456789", 8);
    return (co);
}

int convert_n(int nb, char *base, int mod)
{
    int res = 0;

    if (nb >= mod)
        convert_n(nb / mod, base, mod);
    res = nb % mod;
    return (res);
}

int my_getnbr_stop(char const *str, int i, int stop)
{
    int nb = 0;
    int c = 0;

    for (; (str[i] != '\0' && c <= stop) && str[i] >= '0'
    && str[i] <= '9'; i++, c++) {
        nb = (nb + str[i] - 48) * 10;
    }
    nb = nb / 10;
    return (nb);
}
