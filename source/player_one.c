/*
** EPITECH PROJECT, 2021
** player_one.c
** File description:
** send position in other terminal
*/
#include "my.h"

void send_signal(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR2) {
    }
    if (signum == SIGUSR1) {
    }
}

int check_if_in_map(size_t answer, char *buffer)
{
    if (answer != 3) {
        my_printf("wrong position\n");
        return 84;
    } else if (buffer[0] < 'A' || buffer[0] > 'H') {
        my_printf("wrong position\n");
        return 84;
    }
    if (buffer[1] < '0' || buffer[1] > '8') {
        my_printf("wrong position\n");
        return 84;
    }
    return 0;
}

void check_if_touch(struct sigaction siga, coordonates_s pos, char **ref)
{
    int nb = 0;

    sigaction(SIGUSR2, &siga, NULL);
    pause();
    sigaction(SIGUSR2, &siga, NULL);
    nb = usleep(90000);
    if (nb == 0) {
        my_printf("%c%c: missed\n\n", pos.letter, pos.number);
        put_in_map(pos, 0, ref);
    } else {
        my_printf("%c%c: hit\n\n", pos.letter, pos.number);
        put_in_map(pos, 1, ref);
    }
}

void signal_attack(struct sigaction siga, char *buffer, char **ref, int intnb)
{
    coordonates_s pos;

    pos.letter = buffer[0];
    pos.number = buffer[1];
    for (int i = '@'; i != buffer[0]; i++) {
        kill(intnb, SIGUSR1);
        usleep(100);
    }
    usleep(100000);
    for (int i = '0'; i != buffer[1]; i++) {
        kill(intnb, SIGUSR1);
        usleep(100);
    }
    check_if_touch(siga, pos, ref);
}

int attack(struct sigaction siga, char **usr, char **ref, int intnb)
{
    size_t len = 32;
    size_t answer;
    char *buffer = (char *)malloc(len * sizeof(char));
    int nb = 0;

    siga.sa_sigaction = &send_signal;
    sigaction(SIGUSR2, &siga, NULL);
    usleep(1000000);
    my_printf("attack: ");
    answer = getline(&buffer, &len, stdin);
    nb = check_if_in_map(answer, buffer);
    if (nb == 84) {
        attack(siga, usr, ref, intnb);
        free(buffer);
        return 0;
    }
    signal_attack(siga, buffer, ref, intnb);
    free(buffer);
    return 0;
}
