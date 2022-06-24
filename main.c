/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/
#include "my.h"

int if_won(struct sigaction siga, char **usr, char **ref)
{
    int nb = 0;

    siga.sa_sigaction = &send_signal;
    sigaction(SIGUSR1, &siga, NULL);
    nb = usleep(100000);
    if (nb == -1) {
        display_map(ref, usr);
        my_printf("I won\n");
        return 0;
    }
    return 1;
}

int navy(int ac, char **av)
{
    struct sigaction siga;
    int nb = 0;
    int check = 0;

    siga.sa_flags = SA_SIGINFO;
    siga.sa_sigaction = &connection;
    if (ac == 1)
        return 84;
    check = player_one(siga, ac, av[1], check);
    if (check == 1)
        return 0;
    else if (check == 2)
        return 1;
    nb = player_two(siga, ac, av, nb);
    if (nb == 84)
        return 84;
    else if (nb == 1)
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    int nb = 0;

    if (ac == 2 && my_strcmp("-h", av[1]) == 0) {
        display_help();
        return 0;
    }
    nb = navy(ac, av);
    if (nb == 84)
        return 84;
    return nb;
}
