/*
** EPITECH PROJECT, 2021
** cutpos
** File description:
** cutpos
*/
#include "../include/my.h"

char **alloc(char const *str)
{
    char **final;
    int len = non_alpha(str);
    int nbr_char = bigger(str);

    final = malloc(sizeof(char *) * (len + 2));
    for (int i = 0; str[i] != '\0'; i++) {
        final[i] = malloc(sizeof(char) * nbr_char);
    }
    return (final);
}

int show_string_array(char *const *array)
{
    int i = 0;

    for (; array[i] != NULL; i++) {
        my_printf("%s\n", array[i]);
    }
    return (0);
}
