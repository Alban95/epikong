/*
** gravity2.c for epi in /home/lecoq_m/epikong/etape_3/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Fri Jun 19 02:26:14 2015 Maxime LECOQ
** Last update Fri Jun 19 02:28:17 2015 Maxime LECOQ
*/

#include        "epi.h"

int             down_m(t_struct *st, int nb, t_pos pos)
{
  while (nb > 0)
    {
      st->tmap[pos.y][pos.x] = '.';
      st->tmap[pos.y + 1][pos.x] = 'm';
      pos.y++;
      nb--;
    }
  check_bloquant(st->tmap[pos.y + 1][pos.x], 2, st);
  return (nb);
}

int             check_m(t_struct *st, t_pos pos)
{
  int           how;
  int           i;

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

int             gravity_monster(t_struct *st)
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
