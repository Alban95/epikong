/*
** check_go.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 13:15:17 2015 Maxime LECOQ
** Last update Thu Jun 18 20:51:03 2015 Maxime LECOQ
*/

#include        "epi.h"

int		up_once(t_struct *st)
{
  if (st->tmap[st->heros.y - 1][st->heros.x] != 'm'
      && st->tmap[st->heros.y - 1][st->heros.x] != 'w')
    {
      st->heros.fl = 3;
      st->tmap[st->heros.y][st->heros.x] = '.';
      st->tmap[st->heros.y - 1][st->heros.x] = 'i';
      st->heros.y--;
      st->tmap = change_bad_char(st->tmap, st->tab);
      fct_ptr(st);
      SDL_Flip(st->ecran);
      return (0);
    }
  return (-1);
}

int		check_scale(t_struct *st)
{
  if (st->tab[st->heros.y][st->heros.x] == 's')
    {
      up_once(st);
      return (0);
    }
  return (-1);
}

int		check_up(t_struct *st)
{
  if (st->tmap[st->heros.y][st->heros.x] == '.'
      || st->tmap[st->heros.y][st->heros.x] == 'i')
    {
      if (up_once(st) == 0)
	up_once(st);
      return (0);
    }
  return (-1);
}

int		check_door(t_struct *st)
{
  if (st->tab[st->heros.y][st->heros.x] == 'o')
    {
      if (st->key == 1)
	st->end_map = 42;
    }
  return (-1);
}
