/*
** init_sdl.c for sdl in /home/lecoq_m/epikong/etape_1
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Wed Jun 17 21:18:44 2015 Maxime LECOQ
** Last update Sat Jun 20 02:02:39 2015 canivenc clement
*/

#include	"epi.h"

int		check_level_2(t_struct *st, int flag)
{
  if (st->sound == 3)
    if (flag != 3)
      {
	st->musique = Mix_LoadWAV("./conf/song/fire.wav");
	Mix_VolumeChunk(st->musique, MIX_MAX_VOLUME/2);
	Mix_PlayChannel(1, st->musique, 0);
	flag = 3;
      }
  return (flag);
}

int		check_level(t_struct *st, int flag)
{
  if (st->sound == 1)
    if (flag != 1)
      {
	st->musique = Mix_LoadWAV("./conf/song/castle.wav");
	Mix_VolumeChunk(st->musique, MIX_MAX_VOLUME/2);
	Mix_PlayChannel(1, st->musique, 0);
	flag = 1;
      }
  if (st->sound == 2)
    {
      if (flag != 2)
	{
	  st->musique = Mix_LoadWAV("./conf/song/snow.wav");
	  Mix_VolumeChunk(st->musique, MIX_MAX_VOLUME/2);
	  Mix_PlayChannel(1, st->musique, 0);
	  flag = 2;
	}
    }
  flag = check_level_2(st, flag);
  return (flag);
}

int		init_little_sound(t_struct *st)
{
  st->saut = Mix_LoadWAV("./conf/song/sound/saut.wav");
  Mix_VolumeChunk(st->saut, MIX_MAX_VOLUME/10);
  st->game_over = Mix_LoadWAV("./conf/song/sound/game_over.wav");
  Mix_VolumeChunk(st->game_over, MIX_MAX_VOLUME/2);
  st->win = Mix_LoadWAV("./conf/song/sound/monde-termine.wav");
  Mix_VolumeChunk(st->win, MIX_MAX_VOLUME/2);
  st->one_up = Mix_LoadWAV("./conf/song/sound/one_up.wav");
  Mix_VolumeChunk(st->one_up, MIX_MAX_VOLUME/10);
  st->object = Mix_LoadWAV("./conf/song/sound/object.wav");
  Mix_VolumeChunk(st->object, MIX_MAX_VOLUME);
  st->gun = Mix_LoadWAV("./conf/song/sound/Coin.wav");
  Mix_VolumeChunk(st->gun, MIX_MAX_VOLUME/10);
  return (0);
}

int		init_my_sound(t_struct *st)
{
  static int	flag = 0;

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      my_putstr(Mix_GetError());
      my_putchar('\n');
      return (-1);
    }
  Mix_AllocateChannels(5);
  Mix_Volume(1, MIX_MAX_VOLUME/2);
  init_little_sound(st);
  if (st->sound == 0)
    {
      st->musique = Mix_LoadWAV("./conf/song/menu.wav");
      Mix_VolumeChunk(st->musique, MIX_MAX_VOLUME/2);
      Mix_PlayChannel(1, st->musique, 0);
      st->sound = -1;
      flag = 0;
    }
  else
    flag = check_level(st, flag);
  return (0);
}

int		init_my_sdl(t_struct *st)
{
  st->pos.x = 0;
  st->pos.y = 0;
  st->ecran = NULL;
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1
      || (st->ecran = SDL_SetVideoMode(st->width,
				       st->height, 32, SDL_HWSURFACE)) == NULL)
    return (puterror("Error: In init SDL.\n"));
  SDL_EnableKeyRepeat(100, 100);
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
  init_my_sound(st);
  return (0);
}
