/*
** parse_struct.c for epi in /home/lecoq_m/epikong/etape_2
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 00:47:49 2015 Maxime LECOQ
** Last update Sat Jun 20 05:53:55 2015 Maxime LECOQ
*/

#include	"epi.h"

void		aff_map(t_struct *st)
{
  int		continu;
  SDL_Event	event;

  continu = 1;
  map(st);
  SDL_Flip(st->ecran);
  while (continu == 1)
    {
      SDL_WaitEvent(&event);
      if (check_win(event) == -1)
	exit(0);
      if (go_to_menu_pr(event, st, 2) == 1)
	continu = 0;
      if (event.type == SDL_KEYDOWN)
	{
	  catch_event_map(event, st);
	  st->map_sel = arrange_struct(st->map_sel, st->map);
	  if (event.key.keysym.sym == SDLK_RETURN)
	    continu = 0;
	  map(st);
	  SDL_Flip(st->ecran);
	}
    }
}

char		*have_file(t_struct *st)
{
  if (st->world_sel == 1)
    return (get_file_content(LEVEL1));
  else
    if (st->world_sel == 2)
      return (get_file_content(LEVEL2));
    else
      return (get_file_content(LEVEL3));
}

int		parse_struct2(t_struct *st)
{
  char		*file;

  st->width = 1300;
  st->height = 750;
  st->map_sel = 1;
  if (init_my_sdl(st) == -1
      || (file = have_file(st)) == NULL)
    return (-1);
  st->map = my_getnbr(file);
  free(file);
  if (st->map <= 0 || st->map > 5)
    return (puterror("Error: The number of level-map is changed.\n"));
  aff_map(st);
  return (0);
}
