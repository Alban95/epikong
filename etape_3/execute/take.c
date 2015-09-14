/*
** take.c for epi in /home/lecoq_m/epikong/etape_3/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 23:59:07 2015 Maxime LECOQ
** Last update Fri Jun 19 16:44:13 2015 Maxime LECOQ
*/

#include	"epi.h"

void		take(t_struct *st)
{
  if (st->tab[st->heros.y][st->heros.x] == 'k')
    {
      st->key = 1;
      st->tab = change_key(st);
    }
  else
    if (st->tab[st->heros.y][st->heros.x] == 'l')
      {
	st->heros.life++;
	if (st->heros.life > 3)
	  st->heros.life = 3;
	st->save = st->heros.life;
	put_life(st);
	st->tab[st->heros.y][st->heros.x] = '.';
      }
    else
      if (st->tab[st->heros.y][st->heros.x] == 'g')
	{
	  st->heros.gun = 1;
	  st->tab[st->heros.y][st->heros.x] = '.';
	}
  st->coup--;
}
