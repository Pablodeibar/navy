/*
** EPITECH PROJECT, 2021
** int_char.c
** File description:
** transform int in char
*/
#include "lib.h"

char *int_char(int nb, char *tr)
{
    int i = 0;
    int rest = nb;
    int stay = nb;

    if (nb < 0)
        nb = nb * (-1);
    if (nb >= 0 && nb <= 9) {
        tr[i] = nb + 48;
        return tr;
    }
    for (; nb != 0; i++) {
        rest = nb % 10;
        tr[i] = rest + 48;
        nb /= 10;
    }
    if (stay < 0)
        tr[i] = '-';
    my_revstr(tr);
    return tr;
}
