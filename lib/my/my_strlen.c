/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i;
    int a;

    a = 0;
    for (i = 0; str[i]; i++) {
        a += 1;
    }
    return (a);
}
