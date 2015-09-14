/*
** fonction_pointeur.c for ptr in /home/cloque_b/epikong/etape_1
** 
** Made by alban cloquet
** Login   <cloque_b@epitech.net>
** 
** Started on  Wed Jun 17 20:52:58 2015 alban cloquet
** Last update Fri Jun 19 00:24:56 2015 Maxime LECOQ
*/

#include		"epi.h"

void	place_wall(t_struct *st)
{
  if (st->world_sel == 3)
    st->img = IMG_Load(WALL3);
  else
    if (st->world_sel == 2)
      st->img = IMG_Load(WALL2);
    else
      st->img = IMG_Load(WALL);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void	place_back(t_struct *st)
{
  if (st->world_sel == 3)
    st->img = IMG_Load(BACK3);
  else
    if (st->world_sel == 2)
      st->img = IMG_Load(BACK2);
    else
      st->img = IMG_Load(BACK);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void	place_key(t_struct *st)
{
  if (st->world_sel == 3)
    st->img = IMG_Load(KEY3);
  else
    if (st->world_sel == 2)
      st->img = IMG_Load(KEY2);
    else
      st->img = IMG_Load(KEY1);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void	place_s(t_struct *st)
{
  if (st->world_sel == 3)
    st->img = IMG_Load(ECHELLE3);
  else
    if (st->world_sel == 2)
      st->img = IMG_Load(ECHELLE2);
    else
      st->img = IMG_Load(ECHELLE);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void	place_char(t_struct *st)
{
  if (st->heros.fl == 1)
    st->img = IMG_Load(KONGRIGHT);
  else
    if (st->heros.fl == 2)
      st->img = IMG_Load(KONGLEFT);
    else
      if (st->heros.fl == 3)
	st->img = IMG_Load(KONGBACK);
      else
	if (st->heros.fl == 4)
	  st->img = IMG_Load(KONGBACKS);
	else
	  st->img = IMG_Load(KONG);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}
