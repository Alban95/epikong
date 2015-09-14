/*
** gravity.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 14:11:39 2015 Maxime LECOQ
** Last update Fri Jun 19 02:27:02 2015 Maxime LECOQ
*/

#include	"epi.h"

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

int		check_gravity(t_struct *st, int how)
{
  int		i;

  i = 0;
  if (how > 4)
    {
      st->heros.life = 0;
      i = 1;
    }
  how = down(st, 1, how);
  how = down(st, 2, how);
  how = down(st, 4, how);
  sleep(i);
  while (how > 0)
    how = down(st, 16, how);
  check_bloquant(st->tmap[st->heros.y + 1][st->heros.x], 1, st);
  return (0);
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
  return (check_gravity(st, how));
}
