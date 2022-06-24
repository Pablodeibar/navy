/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1 , char const *s2)
{
    int nb = 0;

    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        nb = nb + (s1[i] - s2[i]);
        if (s1[i] == '\0')
            nb += s2[i];
        if (s2[i] == '\0')
            nb -= s1[i];
    }
    return (nb);
}
