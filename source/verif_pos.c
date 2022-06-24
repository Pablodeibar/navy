/*
** EPITECH PROJECT, 2021
** verifs
** File description:
** verifs
*/
#include "my.h"

void verif_len_let(char *str)
{
    int k = 2;
    int l = 3;
    char nb_fir = str[l];
    char nb_sec = str[l + 3];
    char let_fir = str[k];
    char let_sec = str[k + 3];
    int cpy = nb_fir;

    if (let_fir == let_sec && nb_fir > nb_sec) {
        str[l] = str[l + 3];
        str[l + 3] = cpy;
    }
}

int verif_let_col2(char **file, int i)
{
    int k = 2;
    int l = 3;
    int code1;
    int code2;
    int code3;

    for (int j = 0; j != 2; j++) {
        code1 = verif_len_boat(file[i][0]);
        code2 = verif_let_line(file[i][k]);
        code3 = verif_nums_line(file[i][l]);
        if (code1 == 84 || code2 == 84 || code3 == 84)
            return (84);
        k = k + 3;
        l = l + 3;
    }
    return (0);
}

int verif_let_col(char **file)
{
    int code;

    for (int i = 0; i != 4; i++) {
        verif_len_let(file[i]);
        code = verif_let_col2(file, i);
        if (code == 84)
            return(84);
    }
    return (0);
}
