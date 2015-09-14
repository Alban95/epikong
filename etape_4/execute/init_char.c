/*
** search_pos.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 12:13:12 2015 Maxime LECOQ
** Last update Sat Jun 20 03:28:21 2015 Maxime LECOQ
*/

#include	"epi.h"

int		init_heros(t_struct *st)
{
  int		x;
  int		y;

  st->heros.life = 3;
  st->heros.gun = 0;
  y = 0;
  while (st->tab[y])
    {
      x = 0;
      while (st->tab[y][x])
	{
	  if (st->tab[y][x] == 'i')
	    {
	      st->heros.x = x;
	      st->heros.y = y;
	      return (0);
	    }
	  x++;
	}
      y++;
    }
  return (0);
}

int		init_heros_boss(t_struct *st)
{
  int		x;
  int		y;

  y = 0;
  while (st->tab[y])
    {
      x = 0;
      while (st->tab[y][x])
	{
	  if (st->tab[y][x] == 'i')
	    {
	      st->heros.x = x;
	      st->heros.y = y;
	      return (0);
	    }
	  x++;
	}
      y++;
    }
  return (0);
}

int		init_boss(t_struct *st)
{
  int		x;
  int		y;

  y = 0;
  st->boss.life = 3;
  st->boss.gun = 0;
  while (st->tab[y])
    {
      x = 0;
      while (st->tab[y][x])
	{
	  if (st->tab[y][x] == 'b')
	    {
	      st->boss.x = x;
	      st->boss.y = y;
	      return (0);
	    }
	  x++;
	}
      y++;
    }
  return (0);
}

int		init_monster(t_struct *st)
{
  int		i;
  int		size;

  size = count_char(st->file, 'm');
  if ((st->monster = malloc(sizeof(int) * (size + 1))) == NULL)
    return (-1);
  i = -1;
  while (++i < size)
    st->monster[i] = 1;
  return (0);
}
