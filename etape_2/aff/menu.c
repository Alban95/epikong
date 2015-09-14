/*
** menu.c for epi in /home/lecoq_m/epikong/etape_2
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 04:42:29 2015 Maxime LECOQ
** Last update Thu Jun 18 10:56:20 2015 Maxime LECOQ
*/

#include	"epi.h"

void		aff_menu2(t_struct *st)
{
  if (st->menu == 1)
    st->img = IMG_Load(HOME1);
  else
    if (st->menu == 2)
      st->img = IMG_Load(HOME2);
    else
      if (st->menu == 3)
	st->img = IMG_Load(HOME3);
  SDL_BlitSurface(st->img, NULL, st->ecran, &st->pos);
  free(st->img);
}

int		check_sel(int nb, t_struct *st)
{
  if (nb == 3)
    exit(-1);
  else
    {
      if (nb == 2)
	{
	  write_in(WORLD, "1");
	  write_in(LEVEL1, "1");
	  write_in(LEVEL2, "1");
	  write_in(LEVEL3, "1");
	  write_in(OK, "0");
	  menu(st);
	}
      else
	execute(st);
      return (0);
    }
}
int		check_touch(t_struct *st, SDL_Event event)
{
  if (event.key.keysym.sym == SDLK_DOWN)
    st->menu++;
  else
    if (event.key.keysym.sym == SDLK_UP)
      st->menu--;
  st->menu = arrange_struct(st->menu, 3);
  return (st->menu);
}

int		aff_menu(t_struct *st)
{
  int           continu;
  SDL_Event     event;

  aff_menu2(st);
  SDL_Flip(st->ecran);
  continu = 1;
  while (continu == 1)
    {
      SDL_WaitEvent(&event);
      if (check_win(event) == -1)
        exit(0);
      if (event.type == SDL_KEYDOWN)
        {
	  st->menu = check_touch(st, event);
          if (event.key.keysym.sym == SDLK_RETURN)
            continu = 0;
          aff_menu2(st);
          SDL_Flip(st->ecran);
        }
    }
  return (check_sel(st->menu, st));
}

int		menu(t_struct *st)
{
  st->width = 1300;
  st->height = 750;
  if (init_my_sdl(st) == -1)
    return (puterror("Error during the init of sdl.\n"));
  st->menu = 1;
  return (aff_menu(st));
}
