/*
** EPITECH PROJECT, 2021
** process_info
** File description:
** process_info
*/
#include "my.h"

pid_t len = 0;

void connection(int signum, siginfo_t *info, void *context)
{
    if (signum == SIGUSR1) {
        my_printf("\nenemy connected\n\n");
        len = info->si_pid;
        kill(info->si_pid, SIGUSR2);
    }
    if (signum == SIGUSR2) {
        my_printf("successfully connected\n\n");
    }
}

int infin_game_at(struct sigaction siga, char **ref, char **usr)
{
    int nb = 0;

    display_map(ref, usr);
    while (1) {
        attack(siga, usr, ref, len);
        nb = if_won(siga, usr, ref);
        if (nb == 0)
            return 0;
        wait(siga, usr, ref, len);
        nb = end_game(usr);
        if (nb == 1) {
            nb = usleep(1000);
            kill(len, SIGUSR2);
            display_map(ref, usr);
            my_printf("Enemy won\n");
            return 1;
        }
        display_map(ref, usr);
    }
}

int infin_game_def(struct sigaction siga, char **ref, char **usr, char **av)
{
    int nb = 0;

    display_map(ref, usr);
    while (1) {
        wait(siga, usr, ref, my_getnbr(av[1]));
        nb = end_game(usr);
        if (nb == 1) {
            nb = usleep(1000);
            kill(my_getnbr(av[1]), SIGUSR1);
            display_map(ref, usr);
            my_printf("Enemy won\n");
            return 1;
        }
        attack(siga, usr, ref, my_getnbr(av[1]));
        nb = if_won(siga, usr, ref);
        if (nb == 0)
            return 0;
        display_map(ref, usr);
    }
}

int player_one(struct sigaction siga, int ac, char *str, int check)
{
    char const *map_user = load_file_in_mem(str);
    char const *map_ref = load_file_in_mem("maps/map_ref");
    char **map_split_ref = split_string(map_ref);
    char **map_split_usr;
    int nb = 0;

    map_split_ref[9][17] = '\0';
    map_split_ref[9][18] = '\0';
    if (ac == 2) {
        map_split_usr = apply_pos(map_user, map_ref);
        my_printf("my_pid: %i\n", getpid());
        my_printf("waiting for enemy connection...\n");
        sigaction(SIGUSR1, &siga, NULL);
        pause();
        nb = infin_game_at(siga, map_split_ref, map_split_usr);
        check = 1;
    }
    return check + nb;
}

int player_two(struct sigaction siga, int ac, char **av, int nb)
{
    char const *map_user = load_file_in_mem(av[2]);
    char const *map_ref = load_file_in_mem("maps/map_ref");
    char **map_split_ref = split_string(map_ref);
    char **map_split_usr;

    map_split_ref[9][17] = '\0';
    map_split_ref[9][18] = '\0';
    if (ac == 3 && my_str_isnum(av[1]) == 1) {
        map_split_usr = apply_pos(map_user, map_ref);
        my_printf("my_pid: %i\n", getpid());
        kill(my_getnbr(av[1]), SIGUSR1);
        sigaction(SIGUSR2, &siga, NULL);
        nb = usleep(10000);
        if (nb == 0)
            return 84;
        nb = infin_game_def(siga, map_split_ref, map_split_usr, av);
    }
    return nb;
}
