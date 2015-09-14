/*
** life.c for epi in /home/lecoq_m/epikong/etape_3/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 21:42:44 2015 Maxime LECOQ
** Last update Thu Jun 18 22:07:47 2015 Maxime LECOQ
*/

#include	"epi.h"

int		put_life(t_struct *st)
{
  if (st->heros.life == 3)
    st->img = IMG_Load(LIFE3);
  else
    if (st->heros.life == 2)
      st->img = IMG_Load(LIFE2);
    else
      st->img = IMG_Load(LIFE1);
  st->pos.x = st->width - 120;
  st->pos.y = 0;
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_Flip(st->ecran);
  free(st->img);
  return (0);
}
