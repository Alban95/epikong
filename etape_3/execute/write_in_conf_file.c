/*
** write_in_conf_file.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 11:02:59 2015 Maxime LECOQ
** Last update Fri Jun 19 13:39:27 2015 Maxime LECOQ
*/

#include	"epi.h"

void		write2_conf(t_struct *st, char *str)
{
  char		*file;
  char		*tmp;
  int		nb;

  file = str_nb(st->map_sel);
  tmp = get_file_content(str);
  nb = my_getnbr(tmp);
  free(tmp);
  if (st->map_sel > nb)
    write_in(str, file);
  free(file);
}

void		write_in_conf_file(t_struct *st)
{
  char		*str;
  int		nb;
  char		*file;

  str = get_file_content(WORLD);
  nb = my_getnbr(str);
  file = my_strcat("conf/map/world", str);
  free(str);
  str = my_strcat(file, "/level");
  free(file);
  if (nb < st->world_sel)
    {
      file = str_nb(st->world_sel);
      write_in(WORLD, file);
      free(file);
    }
  else
    write2_conf(st, str);
  free(str);
}
