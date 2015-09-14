/*
** tools.c for epi in /home/lecoq_m/epikong/src/tools
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Wed Jun 17 11:40:33 2015 Maxime LECOQ
** Last update Wed Jun 17 11:40:37 2015 Maxime LECOQ
*/

#include	"epi.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_putchar_err(char c)
{
  write(2, &c, 1);
}

int		puterror(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    my_putchar_err(str[i++]);
  return (-1);
}
