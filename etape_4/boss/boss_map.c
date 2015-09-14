/*
** boss_map.c for epi in /home/lecoq_m/epikong/etape_4/execute/boss
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Fri Jun 19 19:02:57 2015 Maxime LECOQ
** Last update Sun Jun 21 17:43:40 2015 Maxime LECOQ
*/

#include	"epi.h"

int		relaunch_proper_boss(t_struct *st, int life)
{
  t_boss	boss;
  t_heros	heros;

  boss = st->boss;
  heros = st->heros;
  st->width = 1300;
  st->height = 750;
  init_my_sdl(st);
  st->img = IMG_Load(BOSSMAP);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_FreeSurface(st->img);
  SDL_Flip(st->ecran);
  sleep(1);
  init_struct_boss(st);
  st->boss.life = boss.life;
  st->heros.life = heros.life;
  st->heros.gun = heros.gun;
  return (run_boss(st));
}

int		check_end_boss(t_struct *st, int save)
{
  if (st->end_map == 50)
    return (3);
  else
    if (st->boss.life == 0)
      return (1);
    else
      if (st->heros.life > 0 && st->heros.life != save)
	return (relaunch_proper_boss(st, st->heros.life));
      else
	if (st->heros.life == 0)
	  return (-2);
  exit(puterror("Error in end map boss.\n"));
}

int		run_boss(t_struct *st)
{
  while (st->end_map == 1 && st->save == st->heros.life
	 && st->boss.life > 0)
    {
      put_life(st);
      put_life_b(st);
      find_turn(st);
      if (st->turn == 1)
	catch_signal(st);
      else
        {
	  boss_turn(st);
	  move_monster(st);
	}
      st->tmap = change_bad_char(st->tmap, st->tab);
      gravity(st);
      gravity_boss(st);
      fct_ptr(st);
      SDL_Flip(st->ecran);
    }
  SDL_RemoveTimer(st->timer);
  TTF_CloseFont(st->police);
  TTF_Quit();
  return (check_end_boss(st, st->save));
}

int		run_boss_map(t_struct *st)
{
  int		return_value;
  SDL_Event	event;

  if (st->map_sel != 5 || st->end_map != 42)
    return (-1);
  st->width = 1300;
  st->height = 750;
  init_my_sdl(st);
  st->img = IMG_Load(BOSSMAP);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_FreeSurface(st->img);
  SDL_Flip(st->ecran);
  sleep(1);
  SDL_WaitEvent(&event);
  init_struct_boss(st);
  return_value = run_boss(st);
  return (return_value);
}
