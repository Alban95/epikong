/*
** execute.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 09:52:10 2015 Maxime LECOQ
** Last update Fri Jun 19 13:11:57 2015 Maxime LECOQ
*/

#include	"epi.h"

char            *have_name_map(t_struct *st)
{
  char          *str;
  char          *tmp;
  char          *nb;

  nb = str_nb(st->world_sel);
  tmp = my_strcat("conf/map/world", nb);
  free(nb);
  str = my_strcat(tmp, "/map");
  free(tmp);
  if (st->map_sel == 1)
    return (str);
  nb = str_nb(st->map_sel);
  tmp =my_strcat(str, nb);
  free(str);
  free(nb);
  return (tmp);
}

int		have_struct_map(t_struct *st)
{
  if ((st->name = have_name_map(st)) == NULL
      || (st->file = get_file_content(st->name)) == NULL
      || (st->file = put_return(st->file)) == NULL
      || (st->tab = my_str_to_wordtab(st->file, '\n')) == NULL
      || (st->tmap = tabcpy(st->tab)) == NULL)
    return (-1);
  st->width = my_strlen(st->tab[0]) * 29;
  st->height = tablen(st->tab) * 26;
  return (0);
}

void		free_struct(t_struct *st)
{
  free(st->name);
  free(st->file);
  free_tab(st->tab);
  free_tab(st->tmap);
  free(st->monster);
}

int		execute_map(t_struct *st)
{
  write_in_conf_file(st);
  aff_my_level(st);
  if (have_struct_map(st) == -1
      || init_my_sdl(st) == -1)
    return (-1);
  init_heros(st);
  init_monster(st);
  map_not_end(st);
  SDL_Flip(st->ecran);
  free_struct(st);
  return (1);
}
