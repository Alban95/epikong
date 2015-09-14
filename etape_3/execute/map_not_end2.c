/*
** map_not_end2.c for  in /home/lecoq_m/epikong/etape_3/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 22:25:07 2015 Maxime LECOQ
** Last update Fri Jun 19 15:20:38 2015 Maxime LECOQ
*/

#include	"epi.h"

int             relauch_proper(t_struct *st, int life)
{
  aff_my_level(st);
  if (have_struct_map(st) == -1
      || init_my_sdl(st) == -1)
    return (-1);
  init_heros(st);
  st->heros.life = life;
  init_monster(st);
  init_map_game(st);
  st->img = IMG_Load(TEXT_L);
  st->pos.x = st->width - 170;
  st->pos.y = 10;
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_Flip(st->ecran);
  free(st->img);
  return (map_not_end(st));
}

int		check_end_map(t_struct *st, int save)
{
  if (st->heros.life > 0 && st->heros.life != save)
    return (relauch_proper(st, st->heros.life));
  else
    if (st->heros.life != save)
      {
	game_over(st);
	menu(st);
      }
  if (st->end_map == 50)
    return (3);
  return (1);
}
