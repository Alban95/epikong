/*
** error_boss.c for epi in /home/lecoq_m/epikong/etape_4/error_and_parse
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Fri Jun 19 18:32:20 2015 Maxime LECOQ
** Last update Fri Jun 19 18:44:50 2015 Maxime LECOQ
*/

#include	"epi.h"

int		error_boss(char *map)
{
  char		*file;
  char		**tab;
  int		width;
  int		height;

  if (check_existence(map) == -1
      || (file = get_file_content(map)) == NULL
      || check_integer(file, "ibwsm.lg\n") == -1
      || (file = put_return(file)) == NULL
      || (tab = my_str_to_wordtab(file, '\n')) == NULL
      || check_largest(tab) == -1
      || is_present("i", file) != 1
      || is_present("b", file) != 1
      || check_tab(tab) == -1)
    return (puterror("One of Boss map isn't correct.\n"));
  width = my_strlen(tab[0]) * 29;
  height = tablen(tab) * 26;
  if (width > 1300 || height > 750)
    return (puterror("Error: Dimension are too big in Boss Map.\n"));
  free(file);
  free_tab(tab);
  return (0);
}
