/*
** put_color.c for lem in /home/lecoq_m/abc/lur_in/src/tools
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Sat May  2 16:02:20 2015 Maxime LECOQ
** Last update Wed Jun 17 11:40:13 2015 Maxime LECOQ
*/

#include	"epi.h"

int		put_green(char *str)
{
  my_putstr("\033[32;01m");
  my_putstr(str);
  my_putstr("\033[0m");
  return (0);
}

int		put_red(char *str)
{
  my_putstr("\033[31;01m");
  my_putstr(str);
  my_putstr("\033[0m");
  return (0);
}

int		put_red2(char *str)
{
  puterror("\033[31;01m");
  puterror(str);
  puterror("\033[0m");
  return (-1);
}

char		*put_red3(char *str)
{
  puterror("\033[31;01m");
  puterror(str);
  puterror("\033[0m");
  return (NULL);
}

char		**put_red4(char *str)
{
  puterror("\033[31;01m");
  puterror(str);
  puterror("\033[0m");
  return (NULL);
}
