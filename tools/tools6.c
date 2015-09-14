/*
** tools6.c for corewar in /home/lecoq_m/abc/COREWAR/lur_core/src/tools
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Fri Mar 13 10:14:41 2015 Maxime LECOQ
** Last update Wed Jun 17 11:41:11 2015 Maxime LECOQ
*/

#include        "epi.h"

char	*my_strcat2(char *dest, char *src)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (dest[i])
    i++;
  while (src[x])
    dest[i++] = src[x++];
  dest[i] = '\0';
  return (dest);
}

char    *str_nb(int nb)
{
  char  *nbr;
  int   i;
  int   save;

  save = nb;
  i = 0;
  if ((nbr = malloc(sizeof(char *) * 22)) == NULL)
    return (NULL);
  if (nb < 0)
    nb = - nb;
  while (nb > 9)
    {
      nbr[i++] = nb % 10 + 48;
      nb = nb / 10;
    }
  nbr[i] = nb % 10 + 48;
  nbr[++i] = '\0';
  nbr = my_revstr(nbr);
  if (save < 0)
    nbr = my_strcat("-", nbr);
  return (nbr);
}

int             my_tablen(char **tab)
{
  int           i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  dest = malloc(sizeof(*src));
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char    *my_strcpy2(char *dest, char *src)
{
  int   i;

  i = 0;
  dest = malloc(sizeof(*src));
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
