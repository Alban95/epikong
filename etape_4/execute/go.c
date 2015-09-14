/*
** go.c for epi in /home/lecoq_m/epikong/etape_4/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Sat Jun 20 02:13:37 2015 Maxime LECOQ
** Last update Sat Jun 20 02:13:40 2015 Maxime LECOQ
*/

#include	"epi.h"

void		go_up(t_struct *st)
{
  if (check_door(st) == -1)
    if (check_up(st) == -1)
      check_scale(st);
}

void		go_down(t_struct *st)
{
  check_scale2(st);
}

void		go_right(t_struct *st)
{
  if (st->tmap[st->heros.y][st->heros.x + 1] != 'w'
      && st->tmap[st->heros.y][st->heros.x + 1] != 'm'
      && st->tmap[st->heros.y][st->heros.x + 1] != 'b')
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
      && st->tmap[st->heros.y][st->heros.x - 1] != 'm'
      && st->tmap[st->heros.y][st->heros.x - 1] != 'b')
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
      fct_ptr(st);
      SDL_Flip(st->ecran);
      go_left(st);
      fct_ptr(st);
      SDL_Flip(st->ecran);
      go_left(st);
    }
}
