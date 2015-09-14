/*
** aff.c for epi in /home/lecoq_m/epikong/etape_2/aff
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 14:34:24 2015 Maxime LECOQ
** Last update Thu Jun 18 16:23:42 2015 alban cloquet
*/

#include	"epi.h"

int		aff_my_level(t_struct *st)
{
  char		*str;
  char		*nb;
  char		*tmp;

  nb = str_nb(st->map_sel);
  str = my_strcat("conf/img/lvl", nb);
  free(nb);
  tmp = my_strcat(str, "-");
  nb = str_nb(st->world_sel);
  str = my_strcat(tmp, nb);
  free(nb);
  free(tmp);
  tmp = my_strcat(str, ".png");
  st->width = 1300;
  st->height = 750;
  init_my_sdl(st);
  st->img = IMG_Load(tmp);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(tmp);
  SDL_Flip(st->ecran);
  sleep(1);
  free(st->img);
  return (0);
}
