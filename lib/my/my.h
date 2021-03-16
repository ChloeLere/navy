/*
** EPITECH PROJECT, 2020
** my
** File description:
** functions in libmy.a
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <bits/sigaction.h>
#include <ucontext.h>
#include <sys/wait.h>
#include <spawn.h>
#include <sys/select.h>

typedef struct list_element_s
{
    void *data;
    struct list_element_s *next;
    struct list_element_s *prev;
}list_element_t;

typedef struct list_s
{
    int size;
    struct list_element_s *begin;
    struct list_element_s *end;
}*list_t;

typedef struct data_s
{
    int x;
    int y;
    int c;
    int nbr;
}data_t;

typedef struct info_s
{
    int pid;
    int *co;
    int c;
    char *b;
    int loop;
    int res;
}info_t;

typedef struct gnl_s
{
    int gpid;
    int *gco;
    int gc;
    char *gb;
    int gloop;
    int gres;
    char **gmy_map;
    char *gmessage;
    char **gmap_en;
}*gnl_t;

typedef struct statu_game_s
{
    int win;
    int lose;
    int nbr_touch;
    int nbr_t_other;
}*statu_game_t;

void my_putchar(char c);
void my_put_error(char c);
int my_putstr(char const *str);
int my_putstr_error(char *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_nbrlen(int str);
int my_put_nbr_pr(int nb);
int my_getnbr(char const *str);
int my_getnbr_with_i(char const *str, int i);
int my_printf(char *s, ...);
void my_put_nbr_oct(int nb);
void my_put_nbr_uns(unsigned int nb);
void check_string(char *type, va_list argv);
void check_int(char *type, va_list argv);
void check_char(char *type, va_list argv);
int check_other(char *type, va_list argv);
void convert(va_list argv, int base);
void convert_hexa_lower(va_list argv);
void convert_hexa_upper(va_list argv);
void convert_hexa_lower_int(int nbr, va_list argv);
void convert_hexa_lower_long(unsigned long nbr, va_list argv);
void free_all(char **to_free, int nbr_loop);
list_t create_list(void);
int listlen(list_t list);
list_t add_element_end(list_t list, void *data);
list_t add_element_first(list_t list, void *data);
void display_list_1d_arr(list_t list, char *elem_sep);
void display_list_char(list_t list, char *elem_sep);
void display_list_int(list_t list, char *elem_sep);
list_t rm_element_first(list_t list);
list_t rm_element_end(list_t list);
void rm_all(list_t list);
int edit_add(char *str, va_list argv, int add);
int space_or_plus(char str, va_list argv, int add);
void display_all_char(char *str);
void display_p(char *str, va_list argv);
void my_put_nbr_long(long nb);
double my_put_float(double nbr);
void my_put_short(short nb);
int load_file_in_mem(char const *filepath);
char *open_file(char *filepath, char *error_message);
int open_file_int(char *filepath);
int add_zero_or_space(char *str, va_list argv, int add);
void space_char(va_list argv, int nbr);
void zero_or_space_int(char str, va_list argv, int nb_z);
char **char_to_2dchar(char *argv);
int find_size(char *argv, int c);
int find_nb_char(char *argv);
int my_isneg (int n);
void c_free(char **str, int size);
int my_compute_square_root(int nb);
void my_sort_int_array(int *array, int size);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
char *my_revstr(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

void s1(int sig, siginfo_t *i, void *ucontext);
int display_h(char **argv);
int error_handling(int argc, char **argv);
int error_hl_file(int argc, char **argv);
void first_tour_p1(char *file_path);
void action(int sig, siginfo_t *i, void *ucontext);
void first_tour_p2(char *file_path, int pid);
void display_all_map(char **my_map, char **map_enemy);
char **create_map(void);
void free_map(char **map);
char set_map(char **map, int x, int y, int c);
char **edit_map_line(char **map, int **co, int c, int t);
char **edit_map_colone(char **map, int **co, int c, int t);
char **edit_map(char *coordo, char **map);
char **get_map(char *co);
void display_map(char **map);
void draw_map(char **map);
int draw_map_part_2(char map, int temp, int y);
void display_2_first_line(void);
void fsp1_part2(char **map);
char *first_signal_p1(char **map);
void first_signal_p2(int pid, char **map);
int **malloc_co(void);
int **char_to_2d_int(char *coordo);
statu_game_t init_struc(void);
char *convert_to_binary_char(int nbr);
int *send(char *mess, int pid);
char *send_y(char *mess, int pid);
int my_getnbr_stop(char const *str, int i, int stop);
int *convert_to_co(char *binary);
int convert_n(int nb, char *base, int mod);
char *reception_y(int pid, struct sigaction s, char *binary_y);
char *reception_x(int pid, struct sigaction s, char *binary_x, int c);
void reception(void);
void count(int sig, siginfo_t *i, void *ucontext);
char *get_new_mess(void);
void reception_sig(struct sigaction s);
char **find_if_touch(statu_game_t sg, int pid_other, char **map, int *co);
char **said_if_touch(statu_game_t sg, int pid_other, char **my_map, int *co);
void hdlr(int sig);
gnl_t create_struct_p1(info_t data, char *file_path);
gnl_t create_struct_p2(info_t data, char *file_path, int pid_other);
void end_game(statu_game_t sg, char **my_map, int *co);
char *check_nbr_alpha(char *str);
char lower_alpha(char s);
void win_or_lose(statu_game_t sg);
int next_p1(info_t data, gnl_t d, statu_game_t sg);
int next_p2(info_t data, gnl_t g, statu_game_t sg);
char *check_size(char *buf);