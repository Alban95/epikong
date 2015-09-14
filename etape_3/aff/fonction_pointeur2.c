/*
** fonction_pointeur2.c for ff in /home/cloque_b/epikong/etape_1
** 
** Made by alban cloquet
** Login   <cloque_b@epitech.net>
** 
** Started on  Wed Jun 17 20:55:26 2015 alban cloquet
** Last update Fri Jun 19 12:39:12 2015 Maxime LECOQ
*/

#include	"epi.h"

void		place_monster(t_struct *st)
{
  if (st->world_sel == 3)
    st->img = IMG_Load(MONSTER3);
  else
    if (st->world_sel == 2)
      st->img = IMG_Load(MONSTER2);
    else
      st->img = IMG_Load(MONSTER);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_FreeSurface(st->img);
}

void		place_life(t_struct *st)
{
  if (st->world_sel == 3)
    st->img = IMG_Load(LIVE3);
  else
    if (st->world_sel == 2)
      st->img = IMG_Load(LIVE2);
    else
      st->img = IMG_Load(LIVE1);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_FreeSurface(st->img);
}

void		place_gun(t_struct *st)
{
  if (st->world_sel == 3)
    st->img = IMG_Load(WEAPON3);
  else
    if (st->world_sel == 2)
      st->img = IMG_Load(WEAPON2);
    else
      st->img = IMG_Load(WEAPON1);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_FreeSurface(st->img);
}

void		place_door(t_struct *st)
{
  if (st->key == 0)
    st->img = IMG_Load(DOORL);
  else
    st->img = IMG_Load(DOORO);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_FreeSurface(st->img);
}
