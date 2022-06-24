/*
** EPITECH PROJECT, 2021
** player_two.c
** File description:
** program about player two
*/
#include "my.h"

char translate_letter(int i)
{
    char letter = '@';

    for (int j = 0; j < i; j++) {
        letter += 1;
    }
    return letter;
}

int get_all(int i, struct sigaction siga)
{
    int nb = 0;

    siga.sa_sigaction = &send_signal;
    sigaction(SIGUSR1, &siga, NULL);
    pause();
    i++;
    while (1) {
        siga.sa_sigaction = &send_signal;
        sigaction(SIGUSR1, &siga, NULL);
        nb = usleep(20000);
        if (nb == 0)
            break;
        i++;
    }
    return i;
}

void print_if_touch(int i, int pid, coordonates_s pos)
{
    if (i == 0) {
        kill(pid, SIGUSR2);
        my_printf("%c%c: missed\n\n", pos.letter, pos.number);
    }
    else {
        kill(pid, SIGUSR2);
        usleep(10000);
        kill(pid, SIGUSR2);
        my_printf("%c%c: hit\n\n", pos.letter, pos.number);
    }
}

coordonates_s wait(struct sigaction siga, char **str, char **ref, int pid)
{
    int i = 0;
    coordonates_s pos;

    usleep(1000);
    siga.sa_sigaction = &send_signal;
    kill(pid, SIGUSR2);
    my_printf("waiting for enemy's attack...\n");
    i = get_all(i, siga);
    pos.letter = translate_letter(i);
    i = 0;
    i = get_all(i, siga);
    pos.number = i + 48;
    i = change_map(pos, str);
    print_if_touch(i, pid, pos);
    return pos;
}
