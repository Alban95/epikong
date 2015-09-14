/*
** tools2.c for lur in /home/lecoq_m/abc/COREWAR/lur_core/src
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Mon Mar  9 15:42:46 2015 Maxime LECOQ
** Last update Wed Jun 17 11:40:46 2015 Maxime LECOQ
*/

#include        "epi.h"

int     my_put_nbr(int nb)
{
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr(- nb);
      return (0);
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(48 + nb);
  return (0);
}

char    *my_strcut(char *str, int start, int size)
{
  int   i;
  int   j;
  char  *final;

  j = 0;
  i = start;
  if ((final = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (str[i] && j < size)
    {
      final[j] = str[i];
      i++;
      j++;
    }
  final[j] = '\0';
  return (final);
}

int     is_present(char *c, char *str)
{
  int   i;
  int   j;
  int   nb;

  i = 0;
  j = 0;
  nb = 0;
  while (str[i])
    {
      if (str[i] == c[j])
        j++;
      else
        j = 0;
      if (!c[j])
        {
          nb++;
          j = 0;
        }
      i++;
    }
  return (nb);
}

char    *my_strdup(char *src)
{
  char  *dest;
  int   i;

  i = 0;
  if ((dest = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char    *my_strcat(char *s1, char *s2)
{
  int   i;
  int   j;
  char  *end;

  if ((end = malloc(sizeof(char) * (my_strlen(s1))
		    + my_strlen(s2) + 1)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (s1[i])
    end[j++] = s1[i++];
  i = 0;
  while (s2[i])
    end[j++] = s2[i++];
  end[j] = '\0';
  return (end);
}
