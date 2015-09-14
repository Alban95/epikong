/*
** move_monster.c for eef in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 14:52:09 2015 Maxime LECOQ
** Last update Sun Jun 21 17:41:04 2015 Maxime LECOQ
*/

#include	"epi.h"

int		mons_right(t_struct *st, t_pos pos, int i)
{
  if (st->tmap[pos.y + 1][pos.x + 1] == 'w'
      || st->tmap[pos.y + 1][pos.x + 1] == 's')
    {
      if (st->tmap[pos.y][pos.x + 1] == 'w'
	  || st->tmap[pos.y][pos.x + 1] == 'i'
	  || st->tmap[pos.y][pos.x + 1] == 'm'
	  || st->tmap[pos.y][pos.x + 1] == 'b')
	{
	  st->monster[i] = 2;
	  check_bloquant(st->tmap[pos.y][pos.x + 1], 2, st);
	}
      else
	{
	  if (st->tab[pos.y][pos.x] == 'k')
	    st->tmap[pos.y][pos.x] = 'k';
	  else
	    st->tmap[pos.y][pos.x] = '.';
	  st->tmap[pos.y][pos.x + 1] = 'm';
	}
    }
  else
    st->monster[i] = 2;
  return (0);
}

int		mons_left(t_struct *st, t_pos pos, int i)
{
  if (st->tmap[pos.y + 1][pos.x - 1] == 'w'
      || st->tmap[pos.y + 1][pos.x - 1] == 's')
    {
      if (st->tmap[pos.y][pos.x - 1] == 'w'
	  || st->tmap[pos.y][pos.x - 1] == 'i'
	  || st->tmap[pos.y][pos.x - 1] == 'm'
	  || st->tmap[pos.y][pos.x - 1] == 'b')
	{
	  st->monster[i] = 1;
	  check_bloquant(st->tmap[pos.y][pos.x - 1], 2, st);
	}
      else
	{
	  if (st->tab[pos.y][pos.x] == 'k')
	    st->tmap[pos.y][pos.x] = 'k';
	  else
	    st->tmap[pos.y][pos.x] = '.';
	  st->tmap[pos.y][pos.x - 1] = 'm';
	}
    }
  else
    st->monster[i] = 1;
  return (0);
}

int		move_monster(t_struct *st)
{
  t_pos		pos;
  int		i;
  int		size;
  int		save;

  size = count_char(st->file, 'm');
  i = 0;
  save = st->heros.life;
  while (i < size && save == st->heros.life)
    {
      pos = find_pos(st->tmap, i);
      if (pos.y != -42)
	{
	  if (st->monster[i] == 1)
	    mons_right(st, pos, i);
	  else
	    mons_left(st, pos, i);
	}
      i++;
    }
  st->coup++;
  return (0);
}
