/*
** error.c for epi in /home/lecoq_m/epikong/etape_1/error
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Wed Jun 17 20:06:13 2015 Maxime LECOQ
** Last update Thu Jun 18 09:32:12 2015 Maxime LECOQ
*/

#include	"epi.h"

int		check_existence(char *map)
{
  int		fd;

  if ((fd = open(map, O_RDONLY)) == -1)
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

int		check_key_door(char *file)
{
  if (is_present("i", file) != 1)
    return (puterror("Error: the map must countain one entry.\n"));
  else
    if (is_present("o", file) != 1)
      return (puterror("Error: the map must countain one door.\n"));
    else
      if (is_present("k", file) != 1)
	return (puterror("Error: the map must countain one key.\n"));
      else
	return (0);
}
