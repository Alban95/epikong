/*
** parse_struct.c for epi in /home/lecoq_m/epikong/etape_2
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 00:47:49 2015 Maxime LECOQ
** Last update Thu Jun 18 09:29:31 2015 Maxime LECOQ
*/

#include	"epi.h"

void		aff_world2(t_struct *st)
{
  if (st->world == 1)
    world1(st);
  else
    if (st->world == 2)
      world2(st);
    else
      if (st->world == 3)
	world3(st);
}

int		arrange_struct(int nb, int max)
{
  if (nb <= 0)
    return (max);
  else
    if (nb > max)
      return (1);
    else
      return (nb);
}

int		check_win(SDL_Event event)
{
  if (event.type == SDL_QUIT)
    return (-1);
  else
    if (event.type == SDL_KEYDOWN
	&& event.key.keysym.sym == SDLK_ESCAPE)
      return (-1);
  return (0);
}

void		aff_world(t_struct *st)
{
  int		continu;
  SDL_Event	event;

  continu = 1;
  aff_world2(st);
  SDL_Flip(st->ecran);
  while (continu == 1)
    {
      SDL_WaitEvent(&event);
      if (check_win(event) == -1)
	exit(0);
      if (event.type == SDL_KEYDOWN)
	{
	  if (event.key.keysym.sym == SDLK_RIGHT)
	    st->world_sel++;
	  else
	    if (event.key.keysym.sym == SDLK_LEFT)
	      st->world_sel--;
	  st->world_sel = arrange_struct(st->world_sel, st->world);
	  if (event.key.keysym.sym == SDLK_RETURN)
	    continu = 0;
	  aff_world2(st);
	  SDL_Flip(st->ecran);
	}
    }
}

int		parse_struct(t_struct *st)
{
  char		*file;

  st->width = 1300;
  st->height = 750;
  st->world_sel = 1;
  if (init_my_sdl(st) == -1)
    return (-1);
  if ((file = get_file_content(WORLD)) == NULL)
    return (-1);
  st->world = my_getnbr(file);
  free(file);
  if (st->world <= 0 || st->world > 3)
    return (puterror("Error: The number of level-world is changed.\n"));
  aff_world(st);
  parse_struct2(st);
  return (0);
}
