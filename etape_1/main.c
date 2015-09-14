/*
** main.c for main etape 1 in /home/cloque_b/epikong/etape_1/src
** 
** Made by alban cloquet
** Login   <cloque_b@epitech.net>
** 
** Started on  Wed Jun 17 19:38:57 2015 alban cloquet
** Last update Thu Jun 18 18:48:39 2015 Maxime LECOQ
*/

#include	"epi.h"

void		pausa(t_struct *st)
{
  int		continuer = 1;
  SDL_Event	event;

  st = st;
  while (continuer)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	continuer = 0;
      else
	if (event.type == SDL_KEYDOWN
	    && event.key.keysym.sym == SDLK_ESCAPE)
	  continuer = 0;
    }
}

int		main(int ac, char **av)
{
  t_struct	st;

  if (error_step1(ac, av, &st) == -1
      || init_my_sdl(&st) == -1)
    return (-1);
  fct_ptr(&st);
  free(st.name);
  free(st.file);
  free(st.tab);
  SDL_Flip(st.ecran);
  pausa(&st);
  SDL_Quit();
  return (0);
}
