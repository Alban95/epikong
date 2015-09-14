/*
** rush.h for rush in /home/lecoq_m/BocalEmblem/includes
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Fri May 15 21:50:41 2015 Maxime LECOQ
** Last update Thu Jun 18 05:01:46 2015 Maxime LECOQ
*/

#ifndef __TOOLS_H__
# define __TOOLS_H__

typedef struct  s_list
{
  int           val;
  char          *str;
  char          **tab;
  struct s_list *prev;
  struct s_list *next;
}               t_list;

int             my_strlen(char *str);
void            my_putchar(char c);
void            my_putstr(char *str);
void            my_putchar_err(char c);
int             puterror(char *str);
int             my_strcmp(char *s1, char *s2);
char            *my_strstr(char *str, char *to_find);
int             my_strncmp(char *s1, char *s2, int n);
char            *my_strchr(char *str, int c);
char            *my_strcat(char *dest, char *src);
void            my_putnbr(int nb);
int             my_tablen(char **);
char            *my_strcpy(char *, char *);
char            *my_strcpy2(char *, char *);
char            *puterror2(char *str);
char            *concat_str(char *str, char *src);
int             tablen(char **tab);
char            **puterror3(char *str);
char            **tabcpy(char **tab);
int             my_tabcmp(char **tab, char **tab2);
int             count_return(char *str);
int             count_char(char *str, char c);
char            *my_revstr(char *str);
char            *get_next_line(char *str, int init);
char            *get_next_line2(char *str, int init);
int             my_put_nbr_err(int nb);
int             my_str_isnum(char *str);
char            *my_strcat(char *s1, char *s2);
char            *convert_base(char *nbr, char *base_from, char *base_to);
char            *str_nb(int nb);
int             my_getnbr_base(char *str, char *base);
int             my_getnbr(char *str);
char            *my_strcat2(char *dest, char *src);
int             is_present(char *c, char *str);
int             my_strlen(char *str);
void            my_putchar(char c);
void            my_putstr(char *str);
void            my_putchar_err(char c);
int             puterror(char *str);
char            *my_strcut(char *str, int start, int size);
int             my_put_nbr(int nb);
char            *my_strdup(char *src);
int             my_strcmp(char *s1, char *s2);
int             my_strncmp(char *s1, char *s2, int n);
int             my_count_word(char *str, char c);
int             my_word_len(char *str, int pos, char c);
char            *copy_to_tab(char *dest, char *src, int pos, char c);
char            **my_str_to_wordtab(char *str, char c);
int             my_tabcmp(char **tab, char **tab2);
char            **tabcpy(char **tab);
char            *puterror2(char *str);
char            **puterror3(char *str);
int             tablen(char **tab);
void            print_tab(char **tab);
char            **my_str_to_wordtab(char *str, char c);
char            *get_command_line();
void            put_blue(char *str);
int             put_red(char *str);
int             put_green(char *str);
int		my_put_nbr_fd(int nb, int fd);
void		my_putchar_fd(char c, int fd);
void            delete_val(t_list *element);
void            empty_list(t_list * list);
void            delete_list(t_list **list);
int		list_size(t_list *way, t_list *root);
t_list          *create_list(void);
void            my_show_list_right_to_left(t_list *root);
void            my_show_list_left_to_right(t_list *root);
void            add_before_val(t_list *element, char *str);
void            add_after_val(t_list *element, char *str);
char		*get_file_content(char *filename);
void		free_tab(char **tab);
void		write_in(char *file, char *str);

#endif /* !__TOOLS_H__ */
