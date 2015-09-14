/*
** gravity.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 14:11:39 2015 Maxime LECOQ
** Last update Thu Jun 18 23:55:24 2015 Maxime LECOQ
*/

#include	"epi.h"

int		down_m(t_struct *st, int nb, t_pos pos)
{
  while (nb > 0)
    {
      st->tmap[pos.y][pos.x] = '.';
      st->tmap[pos.y + 1][pos.x] = 'm';
      pos.y++;
      nb--;
    }
  return (nb);
}

int		check_m(t_struct *st, t_pos pos)
{
  int		how;
  int		i;

  how = 0;
  i = pos.y + 1;
  while (st->tmap[i] && st->tmap[i][pos.x] != 'w'
	 && st->tmap[i][pos.x] != 'm'
	 && st->tmap[i][pos.x] != 's'
	 && st->tmap[i][pos.x] != 'i')
    {
      how++;
      i++;
    }
  down_m(st, how, pos);
  return (0);
}

int		gravity_monster(t_struct *st)
{
  t_pos         pos;
  int           i;
  int           size;

  size = count_char(st->file, 'm');
  i = 0;
  while (i < size)
    {
      pos = find_pos(st->tmap, i);
      if (pos.y != -42)
	check_m(st, pos);
      i++;
    }
  return (0);
}

int		down(t_struct *st, int max, int nb)
{
  int		i;

  i = 0;
  while (i < max && nb > 0)
    {
      st->tmap[st->heros.y][st->heros.x] = '.';
      st->tmap[st->heros.y + 1][st->heros.x] = 'i';
      st->heros.y++;
      i++;
      nb--;
    }
  fct_ptr(st);
  SDL_Flip(st->ecran);
  return (nb);
}

int		gravity(t_struct *st)
{
  int		how;
  int		i;

  how = 0;
  i = st->heros.y + 1;
  gravity_monster(st);
  if (st->tab[i - 1][st->heros.x] == 's')
    return (0);
  while (st->tmap[i] && st->tmap[i][st->heros.x] != 'w'
	 && st->tmap[i][st->heros.x] != 'm'
	 && st->tmap[i][st->heros.x] != 's')
    {
      how++;
      i++;
    }
  how = down(st, 1, how);
  how = down(st, 2, how);
  how = down(st, 4, how);
  while (how > 0)
    how = down(st, 16, how);
  return (0);
}
