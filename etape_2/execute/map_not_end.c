/*
** map_not_end.c for  in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 11:45:43 2015 Maxime LECOQ
** Last update Fri Jun 19 13:12:17 2015 Maxime LECOQ
*/

#include	"epi.h"

t_ptr                   *init_tab_ptrf()
{
  t_ptr                 *tab;

  if ((tab = malloc(sizeof(*tab) * 7)) == NULL)
    return (NULL);
  tab[0].value = SDLK_UP;
  tab[0].ptrf = &go_up;
  tab[1].value = SDLK_DOWN;
  tab[1].ptrf = &go_down;
  tab[2].value = SDLK_RIGHT;
  tab[2].ptrf = &go_right;
  tab[3].value = SDLK_LEFT;
  tab[3].ptrf = &go_left;
  tab[4].value = SDLK_b;
  tab[4].ptrf = &go_leftup;
  tab[5].value = SDLK_n;
  tab[5].ptrf = &go_rightup;
  tab[6].value = SDLK_m;
  tab[6].ptrf = &go_to_menu;
  return (tab);
}

void		catch_signal(t_struct *st)
{
  SDL_Event     event;
  t_ptr		*tab;
  int		i;

  SDL_WaitEvent(&event);
  tab = init_tab_ptrf();
  if (check_win(event) == -1)
    exit(0);
  i = -1;
  if (event.type == SDL_KEYDOWN)
    {
      while (++i < 7)
	if (event.key.keysym.sym == tab[i].value)
	  (*tab[i].ptrf)(st);
    }
}

char		**change_key(t_struct *st)
{
  int		i;
  int		y;

  i = 0;
  while (st->tab[i])
    {
      y = 0;
      while (st->tab[i][y])
	{
	  if (st->tab[i][y] == 'k')
	    {
	      st->tab[i][y] = '.';
	      return (st->tab);
	    }
	  y++;
	}
      i++;
    }
  return (st->tab);
}

int		map_not_end(t_struct *st)
{

  st->end_map = 1;
  st->key = 0;
  st->heros.fl = 0;
  fct_ptr(st);
  while (st->end_map == 1)
    {
      catch_signal(st);
      if (st->tab[st->heros.y][st->heros.x] == 'k')
	st->key = 1;
      if (st->key == 1)
	st->tab = change_key(st);
      st->tmap = change_bad_char(st->tmap, st->tab);
      move_monster(st);
      st->tmap = change_bad_char(st->tmap, st->tab);
      gravity(st);
      fct_ptr(st);
      SDL_Flip(st->ecran);
    }
  return (0);
}
