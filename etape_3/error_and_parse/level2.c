/*
** level1.c for epi in /home/lecoq_m/epikong/etape_2/error_and_parse
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 02:38:10 2015 Maxime LECOQ
** Last update Thu Jun 18 03:06:06 2015 Maxime LECOQ
*/

#include	"epi.h"

void		level21(t_struct *st)
{
  st->img = IMG_Load(MAP112);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level22(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP212);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP222);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level23(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP312);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP322);
    else
      if (st->map_sel == 3)
	st->img = IMG_Load(MAP332);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level24(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP412);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP422);
    else
      if (st->map_sel == 3)
	st->img = IMG_Load(MAP432);
      else
	if (st->map_sel == 4)
	  st->img = IMG_Load(MAP442);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		level25(t_struct *st)
{
  if (st->map_sel == 1)
    st->img = IMG_Load(MAP512);
  else
    if (st->map_sel == 2)
      st->img = IMG_Load(MAP522);
    else
      if (st->map_sel == 3)
	st->img = IMG_Load(MAP532);
      else
	if (st->map_sel == 4)
	  st->img = IMG_Load(MAP542);
	else
	  if (st->map_sel == 5)
	    st->img = IMG_Load(MAP552);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}
