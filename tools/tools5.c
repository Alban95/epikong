/*
** tools5.c for corewar in /home/lecoq_m/abc/COREWAR/lur_core/src/tools
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Wed Mar 11 17:43:29 2015 Maxime LECOQ
** Last update Wed Jun 17 11:41:05 2015 Maxime LECOQ
*/

#include        "epi.h"

int		next(char *nbr)
{
  int		n;
  int		res;
  int		x;

  x = 0;
  while (nbr[x] == '-' || nbr[x] == '+'
         || (nbr[x] >= '0' && nbr[x] <= '9'))
    x++;
  x = x - 1;
  n = 1;
  res = 0;
  while (x >= 0)
    {
      res = res + (n * (nbr[x] - 48));
      n = n * 10;
      x--;
    }
  return (res);
}

int		my_getnbr(char *str)
{
  int		res;
  int		signe;

  signe = 1;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
        signe = - signe;
      str++;
    }
  res = next(str);
  return (res * signe);
}

unsigned long int	my_getnbrl(char *str)
{
  unsigned long int	res;
  int		signe;

  signe = 1;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
        signe = - signe;
      str++;
    }
  res = next(str);
  return (res * signe);
}

char		*my_strstr(char *str, char *to_find)
{
  int		i;
  int		cpt;

  i = 0;
  cpt = 0;
  while (str[i])
    {
      if (str[i] == to_find[cpt])
	cpt++;
      else
	cpt = 0;
      if (!to_find[cpt])
	{
	  i = i - (cpt - 1);
	  return (str + i);
	}
      i++;
    }
  return (NULL);
}

int     my_strncmp(char *s1, char *s2, int n)
{
  int i;

  i = 0;
  if (n == 0)
    return (-1);
  while ((s1[i] || s2[i]) && i < n)
    {
      if (s1[i] != s2[i])
        return (-1);
      i++;
    }
  if (s1[i] != s2[i])
    return (-1);
  return (0);
}
