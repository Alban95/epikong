/*
** fonction_pointeur2.c for ff in /home/cloque_b/epikong/etape_1
** 
** Made by alban cloquet
** Login   <cloque_b@epitech.net>
** 
** Started on  Wed Jun 17 20:55:26 2015 alban cloquet
** Last update Fri Jun 19 16:29:28 2015 Maxime LECOQ
*/

#include	"epi.h"

void		place_monster(t_struct *st)
{
  st->img = IMG_Load(MONSTER);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		place_life(t_struct *st)
{
  st->img = IMG_Load(LIFE1);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_Flip(st->ecran);
}

void		place_gun(t_struct *st)
{
  st->img = IMG_Load(WEAPON1);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

void		place_door(t_struct *st)
{
  st->img = IMG_Load(DOORL);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}
