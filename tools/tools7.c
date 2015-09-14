/*
** tools7.c for lem in /home/lecoq_m/abc/lur_in
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Tue Apr 14 18:56:58 2015 Maxime LECOQ
** Last update Fri Jun 19 02:13:15 2015 Maxime LECOQ
*/

#include	"epi.h"

char	*puterror2(char *str)
{
  puterror(str);
  return (NULL);
}

char	**puterror3(char *str)
{
  puterror(str);
  return (NULL);
}

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}

void	write_in(char *file, char *str)
{
  int	fd;

  if ((fd = open(file, O_RDWR | O_TRUNC | O_CREAT)) != -1)
    {
      write(fd, str, my_strlen(str));
      close(fd);
    }
}
