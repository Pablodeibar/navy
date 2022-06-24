/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef my_h
    #define my_h

   #include <sys/types.h>
   #include <unistd.h>
   #include <signal.h>
   #include <stdio.h>
   #include <stdlib.h>
   #include <fcntl.h>
   #include <sys/stat.h>

typedef struct coordonates {
    char letter;
    char number;
} coordonates_s;

char *my_revstr(char *str);
void process_info(void);
void my_printf(char *s, ...);
void kill_it(char *nb);
int my_getnbr(char const *str);
int navy(int ac, char **av);
int my_str_isnum(char const *str);
void display_help(void);
int my_strcmp(char const *s1 , char const *s2);
char **alloc(char const *str);
char **alloc(char const *str);
char *load_file_in_mem(char const *filepath);
char **split_string(char const *str);
int my_is_alpha(char const c);
int show_string_array(char *const *array);
int compare(int big, int len);
int bigger(const char *str);
int attack(struct sigaction siga, char **usr, char **ref, int intnb);
coordonates_s wait(struct sigaction siga, char **str, char **ref, int pid);
void send_signal(int signum, siginfo_t *info, void *context);
char **apply_pos(char const *file, char const *map);
int find_letter_line(char first, char second);
void put_boat(char first, char **file, char **map, int i);
int transform_letter(char first);
int verif_j(int j);
int my_strlen(char const *str);
int non_alpha(char const *str);
int verif_let_col(char **file);
int verif_let_line(char c);
int verif_nums_line(char c);
int verif_len_boat(char c);
int verif_let_col2(char **file, int i);
int change_map(coordonates_s pos, char **file);
void put_in_map(coordonates_s pos, int nb, char **file);
int player_two(struct sigaction siga, int ac, char **av, int nb);
int player_one(struct sigaction siga, int ac, char *str, int check);
void connection(int signum, siginfo_t *info, void *context);
void display_map(char **ref, char **usr);
int end_game(char **map_usr);
int if_won(struct sigaction siga, char **usr, char **ref);

#endif