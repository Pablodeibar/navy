/*
** EPITECH PROJECT, 2021
** split
** File description:
** split
*/
#include "../include/my.h"

int my_is_alpha(char const c)
{
    if (c == '\0') {
        return (0);
    } else if (c == '\n') {
        return (0);
    } else {
        return (1);
    }
}

int non_alpha(char const *str)
{
    int non_al = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_is_alpha(str[i]) == 0) {
            non_al++;
        }
    }
    return (non_al);
}

int compare(int big, int len)
{
    if (big > len) {
        return (big);
    } else {
        return (len);
    }
}

int bigger(const char *str)
{
    int big = 0;
    int len = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        if (my_is_alpha(str[j]) == 1) {
            len++;
        } else {
            big = compare(big, len);
            len = 0;
        }
    }
    big = compare(big, len);
    return (big);
}

char **split_string(char const *str)
{
    char **final = alloc(str);
    int j = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_is_alpha(str[i]) == 1) {
            final[j][k] = str[i];
            k++;
        } else {
            final[j][k] = '\0';
            j++;
            k = 0;
        }
    }
    final[j + 1] = NULL;
    return (final);
}
