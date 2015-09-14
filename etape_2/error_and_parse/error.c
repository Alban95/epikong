/*
** error.c for epi in /home/lecoq_m/epikong/etape_1/error
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Wed Jun 17 20:06:13 2015 Maxime LECOQ
** Last update Sun Jun 21 20:41:22 2015 Maxime LECOQ
*/

#include	"epi.h"

int		check_tab(char **tab)
{
  int		i;
  int		x;
  int		y;

  i = 0;
  x = -1;
  while (tab[i][++x])
    if (tab[i][x] != 'w')
      return (-1);
  x = 0;
  y = my_strlen(tab[0]) - 1;
  while (tab[i])
    {
      if (tab[i][x] != 'w' || tab[i][y] != 'w')
	return (-1);
      i++;
    }
  i--;
  x = -1;
  while (tab[i][++x])
    if (tab[i][x] != 'w')
      return (-1);
  return (0);
}

int		end_check(char *file, char **tab, int error, char *map)
{
  if (check_tab(tab) == -1)
    return (-1);
  free(file);
  free_tab(tab);
  if (error == -1)
    {
      puterror("It's the file \"");
      puterror(map);
      return (puterror("\".\n"));
    }
  return (0);
}

int		error(char *map)
{
  char		*file;
  char		**tab;
  int		height;
  int		width;
  int		error;

  error = 0;
  if (check_existence(map) == -1
      || (file = get_file_content(map)) == NULL
      || check_integer(file, "wksmio.lg\n") == -1
      || (file = put_return(file)) == NULL
      || (tab = my_str_to_wordtab(file, '\n')) == NULL
      || check_largest(tab) == -1
      || check_key_door(file) == -1)
    return (-1);
  width = my_strlen(tab[0]) * 29;
  height = tablen(tab) * 26;
  if (width > 1300 || height > 750)
    {
      puterror("Error: Dimension are too big.\n");
      error = -1;
    }
  return (end_check(file, tab, error, map));
}

int		error_step2(int ac, char **av)
{
  av = av;
  if (ac != 1)
    return (puterror("Error: The program doesn't work with argument.\n"));
  else
    if (check_conf_file() == -1)
      return (-1);
  if (error(MAP11) == -1 || error(MAP21) == -1 || error(MAP31) == -1
      || error(MAP41) == -1 || error(MAP51) == -1 || error(MAP12) == -1
      || error(MAP22) == -1 || error(MAP32) == -1 || error(MAP42) == -1
      || error(MAP52) == -1 || error(MAP13) == -1 || error(MAP23) == -1
      || error(MAP33) == -1 || error(MAP43) == -1 || error(MAP53) == -1)
    return (puterror("Error: My map isn't correct.\n"));
  return (0);
}
