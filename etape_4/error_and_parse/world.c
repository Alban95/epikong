/*
** world.c for epi in /home/lecoq_m/epikong/etape_2/error_and_parse
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 00:59:57 2015 Maxime LECOQ
** Last update Thu Jun 18 01:20:17 2015 Maxime LECOQ
*/

#include	"epi.h"

int		world1(t_struct *st)
{
  st->img = IMG_Load(MENU1);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
  return (0);
}

int		world2(t_struct *st)
{
  if (st->world_sel == 1)
    st->img = IMG_Load(MENU21);
  else
    st->img = IMG_Load(MENU22);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
  return (0);
}

int		world3(t_struct *st)
{
  if (st->world_sel == 1)
    st->img = IMG_Load(MENU31);
  else
    if (st->world_sel == 2)
      st->img = IMG_Load(MENU32);
    else
      st->img = IMG_Load(MENU33);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
  return (0);
}
