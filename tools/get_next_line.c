/*
** get_next_line.c for corewar in /home/lecoq_m/abc/COREWAR/lur_core/src
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Mon Mar  9 23:13:33 2015 Maxime LECOQ
** Last update Wed Jun 17 11:38:56 2015 Maxime LECOQ
*/

#include        "epi.h"

char		*get_next_line(char *str, int init)
{
  static int	i = 0;
  int		start;
  int		size;
  char		*line;

  if (init == 1)
    {
      size = my_strlen(str) - 1;
      start = i;
      if (i == size)
	return (NULL);
      while (str[i] && str[i] != '\n')
	i++;
      line = my_strcut(str, start, i - start);
      i++;
      return (line);
    }
  else
    {
      i = 0;
      return (NULL);
    }
}

char		*get_next_line2(char *str, int init)
{
  static int	i = 0;
  int		start;
  int		size;
  char		*line;

  if (init == 1)
    {
      size = my_strlen(str) - 1;
      start = i;
      if (i == size)
	return (NULL);
      while (str[i] && str[i] != '\n')
	i++;
      line = my_strcut(str, start, i - start);
      i++;
      return (line);
    }
  else
    {
      i = 0;
      return (NULL);
    }
}
