/*
** check_go.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 13:15:17 2015 Maxime LECOQ
** Last update Sat Jun 20 11:18:30 2015 Maxime LECOQ
*/

#include        "epi.h"

void		check_bloquant(char c, int fl, t_struct *st)
{
  if (fl == 1)
    {
      if (c == 'm')
	{
	  st->heros.life--;
	  if (st->heros.life > 0)
	    my_putstr("You touch a monster so you lost one life.\n");
	  else
	    my_putstr("You touch a monster and you die.\n");
	}
      if (c == 'b')
	{
	  st->heros.life = 0;
	  my_putstr("You touch a boss so your die.\n");
	}
    }
  else
    if (c == 'i')
      {
	st->heros.life--;
	if (st->heros.life > 0)
	  my_putstr("A monster take you one life.\n");
	else
	  my_putstr("A monster kill you.\n");
      }
}

int		down_once(t_struct *st)
{
  if (st->tmap[st->heros.y + 1][st->heros.x] != 'm'
      && st->tmap[st->heros.y + 1][st->heros.x] != 'w'
      && st->tmap[st->heros.y + 1][st->heros.x] != 'b')
    {
      st->heros.fl = 3;
      st->tmap[st->heros.y][st->heros.x] = '.';
      st->tmap[st->heros.y + 1][st->heros.x] = 'i';
      st->heros.y++;
      st->tmap = change_bad_char(st->tmap, st->tab);
      fct_ptr(st);
      SDL_Flip(st->ecran);
      return (0);
    }
  else
    check_bloquant(st->tmap[st->heros.y + 1][st->heros.x], 1, st);
  return (-1);
}

int		check_scale2(t_struct *st)
{
  if (st->tab[st->heros.y][st->heros.x] == 's')
    {
      down_once(st);
      return (0);
    }
  if (st->tmap[st->heros.y][st->heros.x] == 'i'
      && st->tmap[st->heros.y + 1][st->heros.x] == 's')
    {
      down_once(st);
      return (0);
    }
  return (-1);
}
