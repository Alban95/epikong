/*
** fonction_pointeur.c for ptr in /home/cloque_b/epikong/etape_1
** 
** Made by alban cloquet
** Login   <cloque_b@epitech.net>
** 
** Started on  Wed Jun 17 20:52:58 2015 alban cloquet
** Last update Thu Jun 18 18:49:12 2015 Maxime LECOQ
*/

#include		"epi.h"

void	place_wall(t_struct *st)
{
  st->img = IMG_Load(WALL);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void	place_back(t_struct *st)
{
  st->img = IMG_Load(BACK);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void	place_key(t_struct *st)
{
  st->img = IMG_Load(KEY1);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void	place_s(t_struct *st)
{
  st->img = IMG_Load(ECHELLE);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void	place_char(t_struct *st)
{
  st->img = IMG_Load(KONG);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}
