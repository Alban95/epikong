/*
** map_not_end.c for  in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 11:45:43 2015 Maxime LECOQ
** Last update Sat Jun 20 05:31:05 2015 Maxime LECOQ
*/

#include	"epi.h"

t_ptr                   *init_tab_ptrf()
{
  t_ptr                 *tab;

  if ((tab = malloc(sizeof(*tab) * 10)) == NULL)
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
  tab[7].value = SDLK_t;
  tab[7].ptrf = &take;
  tab[8].value = SDLK_r;
  tab[8].ptrf = &shoot_left;
  tab[9].value = SDLK_y;
  tab[9].ptrf = &shoot_right;
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
      while (++i < 10)
	if (event.key.keysym.sym == tab[i].value)
	  {
	    st->coup++;
	    (*tab[i].ptrf)(st);
	  }
    }
}

void		find_turn(t_struct *st)
{
  if (st->coup == 1)
    {
      st->turn = -st->turn;
      st->coup = 0;
    }
}

int		init_map_game(t_struct *st)
{
  if (st->world_sel == 1)
    st->sound = 1;
  else
    if (st->world_sel == 2)
    st->sound = 2;
    else
      st->sound = 3;
  init_my_sdl(st);
  st->save = st->heros.life;
  st->end_map = 1;
  st->key = 0;
  st->turn = 1;
  st->coup = 0;
  st->time = 75;
  st->postxt.x = st->width - 170;
  st->postxt.y = 30;
  st->heros.fl = 0;
  fct_ptr(st);
  if (TTF_Init() == -1)
    exit(puterror("Error TTF_Init.\n"));
  st->police = TTF_OpenFont(POLICE, 50);
  st->timer = SDL_AddTimer(1000, aff_time, st);
  return (0);
}

int		map_not_end(t_struct *st)
{
  while (st->end_map == 1 && st->save == st->heros.life)
    {
      put_life(st);
      find_turn(st);
      if (st->turn == 1)
	catch_signal(st);
      else
	move_monster(st);
      st->tmap = change_bad_char(st->tmap, st->tab);
      gravity(st);
      fct_ptr(st);
      SDL_Flip(st->ecran);
    }
  SDL_RemoveTimer(st->timer);
  TTF_CloseFont(st->police);
  TTF_Quit();
  return (check_end_map(st, st->save));
}
