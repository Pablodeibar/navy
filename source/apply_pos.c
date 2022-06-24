/*
** EPITECH PROJECT, 2021
** apply
** File description:
** apply
*/
#include "../include/my.h"

int verif_j(int j)
{
    if (j == 4 ) {
        j = j + 2;
    }
    if (j == 5) {
        j = j + 3;
    }else if (j == 1 || j == 3) {
        j++;
    } else {
    }
    return (j);
}

int transform_letter(char first)
{
    switch (first) {
        case 'A': return (1);
        case 'B': return (2);
        case 'C': return (3);
        case 'D': return (4);
        case 'E': return (5);
        case 'F': return (6);
        case 'G': return (7);
        case 'H': return (8);
    }
    return (0);
}

void put_boat(char first, char **file, char **map, int i)
{
    int y_sec;
    int y_fir;
    int k = 3;
    int letter = transform_letter(first);
    int len_boat = file[i][0] - 48;
    int need = 0;

    y_fir = file[i][k] - 48;
    y_sec = file[i][k + 3] - 48;
    len_boat = len_boat + 48;
    if (y_fir != y_sec) {
        for (int j = y_fir; j < (y_sec + 1); j++) {
            map[y_fir + 1][(letter * 2)] = len_boat;
            map[j + 1][(letter * 2)] = len_boat;
        }
    } else {
        for (int j = 0; j <= (len_boat - 48); j++) {
            need = verif_j(j);
            map[y_fir + 1][((letter * 2) + need)] = len_boat;
        }
    }
}

int find_letter_line(char first, char second)
{
    int res = first - second;

    if (res < 0) {
        res = res * -1;
    } else if (res == 0) {
        res = 1;
    }
    return (res);
}

char **apply_pos(char const *file, char const *map)
{
    char **pos = split_string(map);
    char **data = split_string(file);
    int k = 2;
    char first;
    char **err;
    int error;

    pos[9][17] = '\0';
    pos[9][18] = '\0';
    error = verif_let_col(data);
    if (error == 84) {
        
    }
    for (int i = 0; i != 4; i++) {
        first = data[i][k];
        put_boat(first, data, pos, i);
    }
    free(data);
    return (pos);
}

/*
char **apply_pos(char const *file, char const *map)
{
    char **pos = split_string(map);
    char **data = split_string(file);
    int k = 2;
    char first;
    int error;

    pos[9][17] = '\0';
    pos[9][18] = '\0';
    error = verif_let_col(data);
    if (error == 84)
        return(84);
    for (int i = 0; i != 4; i++) {
        first = data[i][k];
        put_boat(first, data, pos, i);
    }
    free(data);
    return (pos);
}
*/