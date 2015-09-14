/*
** tools3.c for corewar in /home/lecoq_m/abc/COREWAR/lur_core/src
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Mon Mar  9 22:14:07 2015 Maxime LECOQ
** Last update Wed Jun 17 11:40:54 2015 Maxime LECOQ
*/

#include        "epi.h"

char    *my_revstr(char *str)
{
  int	x;
  int	begin;
  int	swap;

  x = 0;
  begin = 0;
  while (str[x] != '\0')
    x++;
  x = x - 1;
  while (begin < x)
    {
      swap = str[begin];
      str[begin] = str[x];
      str[x] = swap;
      begin = begin + 1;
      x = x - 1;
    }
  return (str);
}

int     base_nbr(char c, char *base)
{
  int   i;

  i = 0;
  while (base[i] != '\0')
    {
      if (c == base[i])
        return (i);
      i++;
    }
  return (0);
}

int     my_getnbr_base(char *str, char *base)
{
  int   nb_final;
  int   sizeofbase;
  int   sizeofstr;
  int   conv_fact;

  if (str[0] == '\0' || base[0] == '\0')
    return (0);
  if (str[0] == '-')
    return (-my_getnbr_base(str + 1, base));
  sizeofbase = my_strlen(base);
  sizeofstr = my_strlen(str) - 1;
  conv_fact = 1;
  nb_final = 0;
  while (sizeofstr >= 0)
    {
      nb_final = nb_final + base_nbr(str[sizeofstr], base) * conv_fact;
      conv_fact = sizeofbase * conv_fact;
      sizeofstr--;
    }
  return (nb_final);
}

char	*end_convert_base(char *result, int sign, int i)
{
  if (sign == 1)
    result[i++] = '-';
  result[i] = '\0';
  result = my_revstr(result);
  return (result);
}

char    *convert_base(char *nbr, char *base_from, char *base_to)
{
  int   i;
  int   x;
  int   y;
  char  *result;
  int	sign;

  i = 0;
  x = my_getnbr_base(nbr, base_from);
  sign = 0;
  if (x == 0)
    return (my_strdup("0"));
  result = malloc(sizeof(char) * 500);
  if (x < 0)
    {
      x = - x;
      sign = 1;
    }
  y = my_strlen(base_to);
  while (x > 0)
    {
      result[i] = base_to[x % y];
      x = x / y;
      i = i + 1;
    }
  return (end_convert_base(result, sign, i));
}
