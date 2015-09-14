/*
** main.c for main etape 1 in /home/cloque_b/epikong/etape_1/src
** 
** Made by alban cloquet
** Login   <cloque_b@epitech.net>
** 
** Started on  Wed Jun 17 19:38:57 2015 alban cloquet
** Last update Fri Jun 19 14:56:36 2015 Maxime LECOQ
*/

#include	"epi.h"

int		check_event_pause(SDL_Event event, t_struct *st)
{
  if (event.type == SDL_QUIT)
    exit(0);
  else
    if (event.type == SDL_KEYDOWN
	&& event.key.keysym.sym == SDLK_ESCAPE)
      {
	menu(st);
	return (0);
      }
    else
      if (event.type == SDL_KEYDOWN
	  && event.key.keysym.sym == SDLK_n)
	return (0);
  if (event.type == SDL_KEYDOWN
      && event.key.keysym.sym == SDLK_m)
    {
      menu(st);
      return (0);
    }
  return (1);
}

void		pausa(t_struct *st)
{
  int		continuer;
  SDL_Event	event;

  continuer = 1;
  while (continuer)
    {
      SDL_WaitEvent(&event);
      continuer = check_event_pause(event, st);
    }
}

int		main(int ac, char **av)
{
  t_struct	st;

  st.world_sel = 1;
  st.map_sel = 1;
  st.sound = -1;
  if (error_step2(ac, av) == -1
      || menu(&st) == -1)
    return (-1);
  SDL_Quit();
  return (0);
}
