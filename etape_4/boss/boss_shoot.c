/*
** boss_shoot.c for epi in /home/lecoq_m/epikong/etape_4/boss
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Sat Jun 20 01:48:06 2015 Maxime LECOQ
** Last update Sat Jun 20 11:12:04 2015 Maxime LECOQ
*/

#include	"epi.h"

int		check_char_boss(char **map, t_boss boss, int cpt)
{
  int		turn;
  int		i;
  int		tmp;

  i = cpt;
  turn = 0;
  tmp = 0;
  while (turn < 4)
    {
      if (map[boss.y][boss.x + i] == 'i')
	tmp = 1;
      if (tmp == 0
	  && (map[boss.y][boss.x + i] == 'w'
	      || map[boss.y][boss.x + i] == 'm'))
	return (-1);
      turn++;
      i = i + cpt;
    }
  return (1);
}

int		aff_char_boss(char **map, t_boss boss, int cpt, t_struct *st)
{
  int		turn;
  int		i;

  Mix_PlayChannel(2, st->gun, 0);
  i = cpt;
  turn = 0;
  while (turn < 4)
    {
      if (map[boss.y][boss.x + i] == 'i')
	turn = 4;
      else
	{
	  st->tmap[st->boss.y][st->boss.x + i] = 'e';
          fct_ptr(st);
          SDL_Flip(st->ecran);
          fct_ptr(st);
	}
      turn++;
      i = i + cpt;
    }
  return (1);
}

int		shoot_right_boss(t_struct *st)
{
  if (check_char_boss(st->tmap, st->boss, 1) == -1)
    return (0);
  my_putstr("Boss touch you by a gun.\n");
  st->heros.life--;
  aff_char_boss(st->tmap, st->boss, 1, st);
  return (1);
}

int		shoot_left_boss(t_struct *st)
{
  if (check_char_boss(st->tmap, st->boss, -1) == -1)
    return (0);
  my_putstr("Boss touch you by a gun.\n");
  st->heros.life--;
  aff_char_boss(st->tmap, st->boss, -1, st);
  return (1);
}

int		shoot_boss(t_struct *st)
{
  int		i;

  if (st->heros.y == st->boss.y)
    {
      i = st->boss.x - st->heros.x;
      if (i > 0 && i <= 4)
	return (shoot_left_boss(st));
      else
	if (i < 0 && i >= -4)
	  return (shoot_right_boss(st));
	else
	  return (0);
    }
  else
    return (0);
  return (1);
}
