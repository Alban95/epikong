/*
** fonction_pointeur.c for ptr in /home/cloque_b/epikong/etape_1
** 
** Made by alban cloquet
** Login   <cloque_b@epitech.net>
** 
** Started on  Wed Jun 17 20:52:58 2015 alban cloquet
** Last update Fri Jun 19 19:49:20 2015 Maxime LECOQ
*/

#include		"epi.h"

void		place_boss(t_struct *st)
{
  if (st->world_sel == 3)
    st->img = IMG_Load(BOSS3);
  else
    if (st->world_sel == 2)
      st->img = IMG_Load(BOSS2);
    else
      st->img = IMG_Load(BOSS1);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_FreeSurface(st->img);
}
