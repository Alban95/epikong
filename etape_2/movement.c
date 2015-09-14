/*
** movement.c for movement in /home/cloque_b/epikong/etape_2
** 
** Made by alban cloquet
** Login   <cloque_b@epitech.net>
** 
** Started on  Thu Jun 18 11:21:22 2015 alban cloquet
** Last update Thu Jun 18 11:36:36 2015 alban cloquet
*/

#include "epi.h"

int	move_right(t_struct *st)
{
  int	i;
  int	a;

  i = 0;
  while (st->tmap[i])
    {
      a = 0;
      while (st->tmap[i][a])
	{
	  if ((st->tmap[i][a] == 'i') && st->map[i][a + 1] != 'w')
	    {
	      st->tmap[i][a] = '.';
	      st->tmap[i][a + 1] = 'i';
	    }
	  a++;
	}
      i++;
    }
  return (0);
}

int	move_left(t_struct *st)
{
  int	i;
  int	a;

  i = 0;
  while (st->tmap[i])
    {
      a = 0;
      while (st->tmap[i][a])
	{
	  if ((st->tmap[i][a] == 'i') && st->map[i][a - 1] != 'w')
	    {
	      st->tmap[i][a] = '.';
	      st->tmap[i][a - 1] = 'i';
	    }
	  a++;
	}
      i++;
    }
  return (0);
}

