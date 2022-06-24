/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** my_swap
*/
#include "lib.h"

void my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
