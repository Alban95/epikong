/*
** my_time.c for epi in /home/lecoq_m/epikong/etape_3/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Fri Jun 19 11:53:57 2015 Maxime LECOQ
** Last update Sat Jun 20 06:00:18 2015 Maxime LECOQ
*/

#include	"epi.h"

int		init_screen(t_struct *st, SDL_Rect position)
{
  SDL_Surface	*rectangle;

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 90, 30, 32, 0, 0, 0, 0);
  if (st->world_sel == 1)
    SDL_FillRect(rectangle, NULL,
		 SDL_MapRGB(st->ecran->format, 143, 126, 126));
  else
    if (st->world_sel == 2)
    SDL_FillRect(rectangle, NULL,
		 SDL_MapRGB(st->ecran->format, 151, 227, 255));
    else
      SDL_FillRect(rectangle, NULL,
		   SDL_MapRGB(st->ecran->format, 100, 1, 1));
  SDL_BlitSurface(rectangle, NULL, st->ecran, &position);
  SDL_FreeSurface(rectangle);
  return (0);
}

char		*init_str(t_struct *st)
{
  char          *nb;
  char		*str;

  nb = str_nb(st->time);
  str = my_strcat("Time : ", nb);
  free(nb);
  nb = my_strcat(str, "      ");
  free(str);
  return (nb);
}

void		aff_text(t_struct *st, SDL_Rect pos, char *str)
{
  SDL_Color     black =
    {
      0,
      0,
      0
    };
  SDL_Surface	*txt;

  txt = NULL;
  txt = TTF_RenderText_Solid(st->police, str, black);
  txt->w = 90;
  txt->h = 28;
  SDL_BlitSurface(txt, NULL, st->ecran, &pos);
  SDL_FreeSurface(txt);
}

Uint32          aff_time(Uint32 intervalle, void *param)
{
  t_struct	*st;
  char          *str;
  SDL_Rect	position;

  st = param;
  position.x = st->width - 170;
  position.y = 30;
  init_screen(st, position);
  str = init_str(st);
  aff_text(st, position, str);
  free(str);
  if (st->time <= 0 && st->save == st->heros.life)
    {
      st->heros.life--;
      SDL_RemoveTimer(st->timer);
    }
  st->time--;
  param = st;
  return (intervalle);
}
