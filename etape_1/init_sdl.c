/*
** init_sdl.c for sdl in /home/lecoq_m/epikong/etape_1
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Wed Jun 17 21:18:44 2015 Maxime LECOQ
** Last update Thu Jun 18 13:37:50 2015 canivenc clement
*/

#include	"epi.h"

int		init_my_sdl(t_struct *st)
{
  st->pos.x = 0;
  st->pos.y = 0;
  st->ecran = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1
      || (st->ecran = SDL_SetVideoMode(st->width,
				       st->height, 32, SDL_HWSURFACE)) == NULL)
    return (puterror("Error: In init SDL.\n"));
  SDL_FillRect(st->ecran, NULL,
	       SDL_MapRGB(st->ecran->format, 143, 126, 126));
  SDL_WM_SetCaption("EPIKONG", NULL);
  SDL_WM_SetIcon(IMG_Load("./conf/img/logo.png"), NULL);
  return (0);
}
