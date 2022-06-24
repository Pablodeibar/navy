/*
** EPITECH PROJECT, 2021
** verifline
** File description:
** verifline
*/
#include "my.h"

int verif_let_line(char c)
{
    if(c >= 'A' && c <= 'H') {
        return (0);
    } else {
        return(84);
    }
}

int verif_nums_line(char c)
{
    if (c >= '1' && c <= '8') {
        return(0);
    } else {
        return(84);
    }
}

int verif_len_boat(char c)
{
    if (c >= '2' && c <= '5') {
        return(0);
    } else {
        return(84);
    }
}
