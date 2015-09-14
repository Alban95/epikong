/*
** move_lateral.c for epi in /home/lecoq_m/epikong/etape_4/boss
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Sat Jun 20 03:31:15 2015 Maxime LECOQ
** Last update Sat Jun 20 11:20:41 2015 Maxime LECOQ
*/

#include	"epi.h"

int		move_right(t_struct *st)
{
  if (st->tmap[st->boss.y][st->boss.x + 1] == 'i')
    {
      st->heros.life = 0;
      my_putstr("The boss touch you so you are dead.\n");
      return (0);
    }
  if (check_valid_case(st->tmap[st->boss.y][st->boss.x + 1]) == 1
      && check_valid_case_sol(st->tmap[st->boss.y + 1][st->boss.x + 1]) == 1)
    {
      st->tmap[st->boss.y][st->boss.x + 1] = 'b';
      st->tmap[st->boss.y][st->boss.x] = '.';
      st->boss.x++;
    }
  else
    if (check_valid_case_sol(st->tmap[st->boss.y + 1][st->boss.x + 1]) != 1
        && check_valid_case_sol(st->tmap[st->boss.y + 1][st->boss.x + 2]) == 1
        && check_valid_case(st->tmap[st->boss.y][st->boss.x + 1]) == 1
        && check_valid_case(st->tmap[st->boss.y][st->boss.x + 2]) == 1)
      {
	Mix_PlayChannel(2, st->saut, 0);
        st->tmap[st->boss.y][st->boss.x + 2] = 'b';
        st->tmap[st->boss.y][st->boss.x] = '.';
        st->boss.x = st->boss.x + 2;
      }
  return (0);
}
