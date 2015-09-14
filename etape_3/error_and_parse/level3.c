/*
** level1.c for epi in /home/lecoq_m/epikong/etape_2/error_and_parse
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 02:38:10 2015 Maxime LECOQ
** Last update Thu Jun 18 03:05:51 2015 Maxime LECOQ
*/

#include	"epi.h"

void		level31(t_struct *st)
{
  st->img = IMG_Load(MAP113);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level32(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP213);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP223);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level33(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP313);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP323);
    else
      if (st->map_sel == 3)
	st->img = IMG_Load(MAP333);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level34(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP413);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP423);
    else
      if (st->map_sel == 3)
	st->img = IMG_Load(MAP433);
      else
	if (st->map_sel == 4)
	  st->img = IMG_Load(MAP443);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level35(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP513);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP523);
    else
      if (st->map_sel == 3)
	st->img = IMG_Load(MAP533);
      else
	if (st->map_sel == 4)
	  st->img = IMG_Load(MAP543);
	else
	  if (st->map_sel == 5)
	    st->img = IMG_Load(MAP553);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}
