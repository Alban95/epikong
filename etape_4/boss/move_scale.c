/*
** move_scale.c for epi in /home/lecoq_m/epikong/etape_4/boss
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Sat Jun 20 04:47:31 2015 Maxime LECOQ
** Last update Sat Jun 20 04:56:41 2015 Maxime LECOQ
*/

#include	"epi.h"

int		move_down(t_struct *st)
{
  if (st->tab[st->boss.y + 1][st->boss.x] == 's')
    {
      if (st->tmap[st->boss.y + 1][st->boss.x] == 'i')
	{
	  st->heros.life = 0;
	  return (0);
	}
      st->tmap[st->boss.y + 1][st->boss.x] = 'b';
      st->tmap[st->boss.y][st->boss.x] = '.';
      st->boss.y++;
      return (1);
    }
  return (0);
}

int		move_up(t_struct *st)
{
  if (st->tab[st->boss.y - 1][st->boss.x] == 's'
      && st->tab[st->boss.y][st->boss.x] == 's')
    {
      if (st->tmap[st->boss.y - 1][st->boss.x] == 'i')
	{
	  st->heros.life = 0;
	  return (0);
	}
      st->tmap[st->boss.y - 1][st->boss.x] = 'b';
      st->tmap[st->boss.y][st->boss.x] = '.';
      st->boss.y--;
      return (1);
    }
  return (0);
}

int		check_scale_boss(t_struct *st)
{
  if (st->boss.y - st->heros.y < 0)
    return (move_down(st));
  else
    if (st->boss.y - st->heros.y > 0)
      return (move_up(st));
    else
      return (0);
}
