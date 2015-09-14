/*
** init_sdl.c for sdl in /home/lecoq_m/epikong/etape_1
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Wed Jun 17 21:18:44 2015 Maxime LECOQ
** Last update Fri Jun 19 23:06:52 2015 Maxime LECOQ
*/

#include	"epi.h"

int             init_my_sound()
{
  Mix_Music     *musique;

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      my_putstr(Mix_GetError());
      my_putchar('\n');
      return (-1);
    }
  musique = Mix_LoadMUS("./conf/song/menu.wav");
  Mix_PlayMusic(musique, -1);
  return (0);
}

int		init_my_sdl(t_struct *st)
{
  st->pos.x = 0;
  st->pos.y = 0;
  st->ecran = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1
      || (st->ecran = SDL_SetVideoMode(st->width,
				       st->height, 32, SDL_HWSURFACE)) == NULL)
    return (puterror("Error: In init SDL.\n"));
  SDL_EnableKeyRepeat(50, 50);
  if (st->world_sel == 1)
    SDL_FillRect(st->ecran, NULL,
		 SDL_MapRGB(st->ecran->format, 143, 126, 126));
  else
    if (st->world_sel == 2)
      SDL_FillRect(st->ecran, NULL,
		 SDL_MapRGB(st->ecran->format, 151, 227, 255));
    else
      if (st->world_sel == 3)
	SDL_FillRect(st->ecran, NULL,
		     SDL_MapRGB(st->ecran->format, 100, 1, 1));
  SDL_WM_SetCaption("EPIKONG", NULL);
  SDL_WM_SetIcon(IMG_Load("./conf/img/logo.png"), NULL);
  init_my_sound();
  return (0);
}
