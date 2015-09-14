/*
** level1.c for epi in /home/lecoq_m/epikong/etape_2/error_and_parse
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 02:38:10 2015 Maxime LECOQ
** Last update Thu Jun 18 03:34:20 2015 Maxime LECOQ
*/

#include	"epi.h"

void		level11(t_struct *st)
{
  st->img = IMG_Load(MAP111);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level12(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP211);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP221);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level13(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP311);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP321);
    else
      if (st->map_sel == 3)
	st->img = IMG_Load(MAP331);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level14(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP411);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP421);
    else
      if (st->map_sel == 3)
	st->img = IMG_Load(MAP431);
      else
	if (st->map_sel == 4)
	  st->img = IMG_Load(MAP441);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level15(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP511);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP521);
    else
      if (st->map_sel == 3)
	st->img = IMG_Load(MAP531);
      else
	if (st->map_sel == 4)
	  st->img = IMG_Load(MAP541);
	else
	  if (st->map_sel == 5)
	    st->img = IMG_Load(MAP551);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}
