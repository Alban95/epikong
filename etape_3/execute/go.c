/*
** go.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 12:03:14 2015 Maxime LECOQ
** Last update Fri Jun 19 15:05:34 2015 Maxime LECOQ
*/

#include	"epi.h"

void		go_up(t_struct *st)
{
  if (check_door(st) == -1)
    if (check_scale(st) == -1)
      check_up(st);
}

void		go_down(t_struct *st)
{
  check_scale2(st);
}

void		go_right(t_struct *st)
{
  if (st->tmap[st->heros.y][st->heros.x + 1] != 'w'
      && st->tmap[st->heros.y][st->heros.x + 1] != 'm')
    {
      st->heros.fl = 1;
      if (st->tab[st->heros.y][st->heros.x] == 's')
	st->tmap[st->heros.y][st->heros.x] = 's';
      else
	if (st->tab[st->heros.y][st->heros.x] == 'o')
	  st->tmap[st->heros.y][st->heros.x] = 'o';
	else
	  st->tmap[st->heros.y][st->heros.x] = '.';
      st->tmap[st->heros.y][st->heros.x + 1] = 'i';
      st->heros.x++;
    }
  else
    check_bloquant(st->tmap[st->heros.y][st->heros.x + 1], 1, st);
}

void		go_left(t_struct *st)
{
  if (st->tmap[st->heros.y][st->heros.x - 1] != 'w'
      && st->tmap[st->heros.y][st->heros.x - 1] != 'm')
    {
      st->heros.fl = 2;
      if (st->tab[st->heros.y][st->heros.x] == 's')
	st->tmap[st->heros.y][st->heros.x] = 's';
      else
	if (st->tab[st->heros.y][st->heros.x] == 'o')
	  st->tmap[st->heros.y][st->heros.x] = 'o';
	else
	  st->tmap[st->heros.y][st->heros.x] = '.';
      st->tmap[st->heros.y][st->heros.x - 1] = 'i';
      st->heros.x--;
    }
  else
    check_bloquant(st->tmap[st->heros.y][st->heros.x - 1], 1, st);
}

void		go_leftup(t_struct *st)
{
  if (up_once(st) == 0)
    {
      go_left(st);
      go_left(st);
    }
}
