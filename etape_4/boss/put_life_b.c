/*
** put_life_b.c for epi in /home/lecoq_m/epikong/etape_4/boss
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Sun Jun 21 17:44:30 2015 Maxime LECOQ
** Last update Sun Jun 21 18:10:25 2015 Maxime LECOQ
*/

#include	"epi.h"

void		init_screen_life(t_struct *st, SDL_Rect pos)
{
  SDL_Surface   *rectangle;

  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 30, 32, 0, 0, 0, 0);
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
  SDL_BlitSurface(rectangle, NULL, st->ecran, &pos);
  SDL_FreeSurface(rectangle);
}

void		put_text(t_struct *st, SDL_Rect pos)
{
  SDL_Color     red =
    {
      255,
      0,
      0
    };
  SDL_Surface   *txt;

  txt = NULL;
  txt = TTF_RenderText_Solid(st->police, "Boss Live :        ", red);
  txt->w = 120;
  txt->h = 28;
  SDL_BlitSurface(txt, NULL, st->ecran, &pos);
  SDL_FreeSurface(txt);
}

int             put_life_b(t_struct *st)
{
  SDL_Rect	pos;

  pos.x = st->width - 200;
  pos.y = 60;
  init_screen_life(st, pos);
  put_text(st, pos);
  if (st->boss.life == 3)
    st->img = IMG_Load(LIFE3);
  else
    if (st->boss.life == 2)
      st->img = IMG_Load(LIFE2);
    else
      st->img = IMG_Load(LIFE1);
  pos.x = st->width - 95;
  pos.y = 60;
  SDL_BlitSurface(st->img, NULL, st->ecran, &pos);
  SDL_Flip(st->ecran);
  free(st->img);
  return (0);
}
