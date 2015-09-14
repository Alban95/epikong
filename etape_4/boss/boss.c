/*
** boss.c for epi in /home/lecoq_m/epikong/etape_4/boss
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Sat Jun 20 01:44:04 2015 Maxime LECOQ
** Last update Sat Jun 20 11:10:43 2015 Maxime LECOQ
*/

#include	"epi.h"

int		move_boss(t_struct *st)
{
  if (check_scale_boss(st) == 1)
    return (0);
  if (st->boss.x - st->heros.x > 0)
    move_left(st);
  else
    if (st->boss.x - st->heros.x < 0)
      move_right(st);
  return (0);
}

int		boss_take(t_struct *st)
{
  if (st->tab[st->boss.y][st->boss.x] == 'l')
    {
      Mix_PlayChannel(2, st->one_up, 0);
      st->tab[st->boss.y][st->boss.x] = '.';
      st->boss.life++;
      my_putstr("Boss take a life.\n");
      if (st->boss.life > 3)
	st->boss.life = 3;
      boss_turn(st);
      return (1);
    }
  else
    if (st->tab[st->boss.y][st->boss.x] == 'g')
      {
	Mix_PlayChannel(2, st->object, 0);
	my_putstr("Boss take a weapon.\n");
	st->tab[st->boss.y][st->boss.x] = '.';
	st->boss.gun = 1;
	boss_turn(st);
	return (1);
      }
  return (-1);
}

int		boss_turn(t_struct *st)
{
  if (boss_take(st) == -1)
    {
      if (st->boss.gun == 1)
	{
	  if (shoot_boss(st) == 0)
	    move_boss(st);
	}
      else
	move_boss(st);
    }
  return (0);
}
