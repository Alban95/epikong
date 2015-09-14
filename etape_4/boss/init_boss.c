/*
** init_boss.c for epi in /home/lecoq_m/epikong/etape_4/boss
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Fri Jun 19 20:02:29 2015 Maxime LECOQ
** Last update Sat Jun 20 05:31:53 2015 Maxime LECOQ
*/

#include	"epi.h"

char            *have_name_map_boss(t_struct *st)
{
  if (st->world_sel == 1)
    return (BOSSM1);
  else
    if (st->world_sel == 2)
      return (BOSSM2);
    else
      return (BOSSM3);
}

int             init_map_game_boss(t_struct *st)
{
  init_my_sdl(st);
  st->save = st->heros.life;
  st->end_map = 1;
  st->key = 0;
  st->turn = 1;
  st->coup = 0;
  st->time = 50;
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

int             init_struct_boss(t_struct *st)
{
  if ((st->name = have_name_map_boss(st)) == NULL
      || (st->file = get_file_content(st->name)) == NULL
      || (st->file = put_return(st->file)) == NULL
      || (st->tab = my_str_to_wordtab(st->file, '\n')) == NULL
      || (st->tmap = tabcpy(st->tab)) == NULL)
    exit(puterror("Have map boss failed.\n"));
  st->width = my_strlen(st->tab[0]) * 29 + 200;
  st->height = tablen(st->tab) * 26;
  init_heros_boss(st);
  init_boss(st);
  init_monster(st);
  init_map_game_boss(st);
  st->img = IMG_Load(TEXT_L);
  st->pos.x = st->width - 170;
  st->pos.y = 10;
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_Flip(st->ecran);
  return (0);
}
