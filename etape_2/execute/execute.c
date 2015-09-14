/*
** execute.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 09:52:10 2015 Maxime LECOQ
** Last update Fri Jun 19 13:01:25 2015 Maxime LECOQ
*/

#include	"epi.h"

int		check_end_of_game(t_struct *st)
{
  char		*file;

  if ((file = get_file_content(OK)) == NULL)
    return (0);
  st->ok = my_getnbr(file);
  free(file);
  if (st->ok == 1)
    return (1);
  else
    return (0);
}

int		winneur(t_struct *st)
{
  st->width = 1300;
  st->height = 750;
  init_my_sdl(st);
  st->img = IMG_Load(WIN);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_Flip(st->ecran);
  sleep(2);
  return (0);
}

int		change_conf(t_struct *st)
{
  st->map_sel++;
  st->map++;
  if (st->map_sel > 5)
    {
      st->world_sel++;
      st->world++;
      st->map_sel = 1;
      st->map = 1;
      if (st->world_sel > 3)
	{
	  winneur(st);
	  menu(st);
	  return (1);
	}
    }
  return (0);
}

int		game_over(t_struct *st)
{
  st->width = 1300;
  st->height = 750;
  init_my_sdl(st);
  st->img = IMG_Load(GAMEOVER);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  SDL_Flip(st->ecran);
  sleep(2);
  return (0);
}

int		execute(t_struct *st)
{
  int		success;

  if (parse_struct(st) == -1
      || init_my_sdl(st) == -1)
    return (-1);
  st->end_game = check_end_of_game(st);
  while (st->end_game == 0)
    {
      success = execute_map(st);
      if (success == 1)
	{
	  if (change_conf(st) == 1)
	    return (0);
	}
      else
	if (success == -1)
	  return (game_over(st));
      st->end_game = check_end_of_game(st);
    }
  return (0);
}
