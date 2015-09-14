/*
** tools4.c for corewar in /home/lecoq_m/abc/COREWAR/lur_core/src
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Tue Mar 10 14:28:07 2015 Maxime LECOQ
** Last update Wed Jun 17 11:40:59 2015 Maxime LECOQ
*/

#include        "epi.h"

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
        return (1);
      i++;
    }
  if (s1[i] != s2[i])
    return (1);
  return (0);
}

int     my_put_nbr_err(int nb)
{
  if (nb == -2147483648)
    {
      puterror("-2147483648");
      return (0);
    }
  if (nb < 0)
    {
      my_putchar_err('-');
      my_put_nbr_err(- nb);
      return (0);
    }
  if (nb > 9)
    {
      my_put_nbr_err(nb / 10);
      my_put_nbr_err(nb % 10);
    }
  else
    my_putchar_err(48 + nb);
  return (0);
}

int     count_char(char *str, char c)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  while (str[i])
    {
      if (str[i] == c)
        cpt++;
      i++;
    }
  return (cpt);
}

int     my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= '0' && str[i] <= '9'))
        i++;
      else
        return (-1);
    }
  return (1);
}
