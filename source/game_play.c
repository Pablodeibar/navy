/*
** EPITECH PROJECT, 2021
** gameplay
** File description:
** gameplay
*/
#include "my.h"

int change_map(coordonates_s pos, char **file)
{
    int let = transform_letter(pos.letter);
    int nb = pos.number - 48;
    int ref = 1;

    if (file[nb + ref][(let * 2)] != '.' && file[nb + ref][(let * 2)] != 'o') {
        file[nb + ref][(let * 2)] = 'x';
        return (1);
    } else {
        file[nb + ref][(let * 2)] = 'o';
        return (0);
    }
}

void put_in_map(coordonates_s pos, int nb, char **file)
{
    int let = transform_letter(pos.letter);
    int ref = 1;
    int nbr = pos.number - 48;

    if (nb == 0) {
        file[nbr + ref][(let * 2)] = 'o';
    } else if (nb == 1) {
        file[nbr + ref][(let * 2)] = 'x';
    }
}

int verif_line_end(char c)
{
    if (c != 'o' && c != 'x' && c != '.' && c != ' ') {
        return (1);
    } else {
        return (0);
    }
}

int end_game2(char *line)
{
    int res;

    for (int j = 2; line[j] != '\0'; j++) {
        res = verif_line_end(line[j]);
        if (res == 1) {
            return (1);
        }
    }
    return (0);
}

int end_game(char **map_usr)
{
    int res;

    for (int i = 2; i < 9; i++) {
        res = end_game2(map_usr[i]);
        if (res == 1) {
            return (0);
        }
    }
    return (1);
}
