/*
** shoot.c for epi in /home/lecoq_m/epikong/etape_4/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Fri Jun 19 16:59:58 2015 Maxime LECOQ
** Last update Sun Jun 21 18:16:43 2015 Maxime LECOQ
*/

#include	"epi.h"

int		check_char(char c)
{
  if (c == 's' || c == '.' || c == 'k' || c == 'o' || c == 'g'
      || c == 'l')
    return (1);
  else
    return (0);
}

char		check_wich_4(char **tab, int y, int x, t_struct *st)
{
  if (tab[y][x] == 'b')
    {
      st->boss.life--;
      if (st->boss.life <= 0)
	return ('.');
      else
	return (tab[y][x]);
    }
  else
    {
      if (tab[y][x] == 'm')
	return ('.');
      else
	if (tab[y][x] != 'i')
	  return (tab[y][x]);
	else
	  return ('.');
    }
}

void		check_left_sh(t_struct *st, int i)
{
  if (st->tmap[st->heros.y][st->heros.x - 1 - i] == 'm')
    st->tmap[st->heros.y][st->heros.x - 1 - i] = '.';
  else
    {
      if (st->tmap[st->heros.y][st->heros.x - 1 - i] == 'b')
	{
	  st->boss.life--;
	  if (st->boss.life == 0)
	    st->tmap[st->heros.y][st->heros.x - 1 - i] = '.';
	}
    }
}

int		check_gun(t_struct *st)
{
  if (st->heros.gun == 0)
    {
      st->coup--;
      return (-1);
    }
  return (0);
}

void		shoot_left(t_struct *st)
{
  int		i;

  i = 0;
  if (check_gun(st) == -1)
    return;
  Mix_PlayChannel(2, st->gun, 0);
  while (i < 4)
    {
      st->heros.fl = 2;
      if (check_char(st->tmap[st->heros.y][st->heros.x - 1 - i]) == 1)
	{
	  st->tmap[st->heros.y][st->heros.x - 1 - i] = 'e';
	  fct_ptr(st);
	  SDL_Flip(st->ecran);
	  st->tmap[st->heros.y][st->heros.x - 1 - i] =
	    check_wich_4(st->tab, st->heros.y, st->heros.x - 1 - i, st);
	  fct_ptr(st);
	}
      else
	{
	  check_left_sh(st, i);
	  i = 4;
	}
      i++;
    }
}
