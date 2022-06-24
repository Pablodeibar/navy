/*
** EPITECH PROJECT, 2021
** infos.c
** File description:
** infos
*/
#include "my.h"

void display_help(void)
{
    my_printf("USAGE\n\t./navy [first_player_pid] navy_positions\n"
    "DESCRIPTIONS\n\t"
    "first_player_id: only for the 2nd player. pid of the first player\n\t"
    "navy_positions: file representing the positions of the ships.\n");
}

void display_map(char **ref, char **usr)
{
    my_printf("my positions:\n");
    show_string_array(usr);
    my_printf("\nenemy's positions:\n");
    show_string_array(ref);
    my_printf("\n");
}
