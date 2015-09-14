/*
** gravity.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 14:11:39 2015 Maxime LECOQ
** Last update Sat Jun 20 03:53:46 2015 Maxime LECOQ
*/

#include	"epi.h"

int		down_b(t_struct *st, int max, int nb)
{
  int		i;

  i = 0;
  while (i < max && nb > 0)
    {
      st->tmap[st->boss.y][st->boss.x] = '.';
      st->tmap[st->boss.y + 1][st->boss.x] = 'b';
      st->boss.y++;
      i++;
      nb--;
    }
  fct_ptr(st);
  SDL_Flip(st->ecran);
  return (nb);
}

int		check_gravity_b(t_struct *st, int how)
{
  if (how > 4)
    {
      st->boss.life = 0;
      my_putstr("Boss dead by Gravity.\n");
    }
  how = down_b(st, 1, how);
  how = down_b(st, 2, how);
  how = down_b(st, 4, how);
  while (how > 0)
    how = down_b(st, 16, how);
  if (st->tmap[st->boss.y + 1][st->boss.x] == 'i')
    st->heros.life = 0;
  return (0);
}

int		gravity_boss(t_struct *st)
{
  int		how;
  int		i;

  how = 0;
  i = st->boss.y + 1;
  if (st->tab[i - 1][st->boss.x] == 's')
    return (0);
  while (st->tmap[i] && st->tmap[i][st->boss.x] != 'w'
	 && st->tmap[i][st->boss.x] != 'm'
	 && st->tmap[i][st->boss.x] != 'i'
	 && st->tmap[i][st->boss.x] != 's')
    {
      how++;
      i++;
    }
  return (check_gravity_b(st, how));
}
