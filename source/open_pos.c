/*
** EPITECH PROJECT, 2021
** openpos
** File description:
** openpos
*/
#include "../include/my.h"

char *load_file_in_mem(char const *filepath)
{
    int i = 0;
    char *final;
    char buffer[1000];

    final = malloc(sizeof(char) * 1000);
    read(open(filepath, O_RDONLY), buffer, 1000);
    for (; i != 1000; i++) {
        final[i] = buffer[i];
    }
    final[i] = '\0';
    return (final);
}
