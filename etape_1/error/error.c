/*
** error.c for epi in /home/lecoq_m/epikong/etape_1/error
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Wed Jun 17 20:06:13 2015 Maxime LECOQ
** Last update Wed Jun 17 23:18:25 2015 Maxime LECOQ
*/

#include	"epi.h"

int		first_check(int ac, char **av)
{
  int		fd;

  if (ac != 2)
    return (puterror("Error: The number of arguments is wrong.\n"));
  else
    if ((fd = open(av[1], O_RDONLY)) == -1)
      return (puterror("Error: The name file isn't correct.\n"));
  close(fd);
  return (0);
}

int		check_integer(char *file, char *base)
{
  int		i;
  int		x;
  int		cpt;

  i = -1;
  while (file[++i])
    {
      x = -1;
      cpt = 0;
      while (base[++x])
	{
	  if (file[i] == base[x])
	    cpt = 1;
	}
      if (cpt == 0)
	return (puterror("Error: File contain bad character.\n"));
    }
  return (0);
}

char		*put_return(char *str)
{
  char		*end;

  if (str[my_strlen(str) - 1] != '\n')
    {
      end = my_strcat(str, "\n");
      free(str);
      return (end);
    }
  else
    return (str);
}

int		check_largest(char **tab)
{
  int		save;
  int		i;

  i = 0;
  save = my_strlen(tab[i]);
  i++;
  while (tab[i])
    {
      if (my_strlen(tab[i]) != save)
	return (puterror("Error : largest isn't the same.\n"));
      i++;
    }
  return (0);
}

int		error_step1(int ac, char **av, t_struct *st)
{
  if (first_check(ac, av) == -1
      || (st->name = my_strdup(av[1])) == NULL
      || (st->file = get_file_content(st->name)) == NULL
      || check_integer(st->file, "wksmio.lg\n") == -1
      || (st->file = put_return(st->file)) == NULL
      || (st->tab = my_str_to_wordtab(st->file, '\n')) == NULL
      || check_largest(st->tab) == -1)
    return (-1);
  st->width = my_strlen(st->tab[0]) * 29;
  st->height = tablen(st->tab) * 26;
  if (st->width > 1300 || st->height > 750)
    return (puterror("Error: Dimension are too big.\n"));
  return (0);
}
