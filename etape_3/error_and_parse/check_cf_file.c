/*
** check_conf_file.c for epi in /home/lecoq_m/epikong/etape_4/error_and_parse
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Sun Jun 21 17:34:34 2015 Maxime LECOQ
** Last update Sun Jun 21 17:36:39 2015 Maxime LECOQ
*/

#include	"epi.h"

int		check_conf_file()
{
  char		*tmp;

  tmp = get_file_content(WORLD);
  if (tmp == NULL || my_strlen(tmp) != 1)
    return (puterror("Error \"conf/map/world\" isn't correct.\n"));
  free(tmp);
  tmp = get_file_content(LEVEL1);
  if (tmp == NULL || my_strlen(tmp) != 1)
    return (puterror("Error \"conf/map/world1/level\" isn't correct.\n"));
  free(tmp);
  tmp = get_file_content(LEVEL2);
  if (tmp == NULL || my_strlen(tmp) != 1)
    return (puterror("Error \"conf/map/world2/level\" isn't correct.\n"));
  free(tmp);
  tmp = get_file_content(LEVEL3);
  if (tmp == NULL || my_strlen(tmp) != 1)
    return (puterror("Error \"conf/map/world3/level\" isn't correct.\n"));
  return (0);
}
