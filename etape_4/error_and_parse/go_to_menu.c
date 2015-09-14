/*
** go_to_menu.c for epi in /home/lecoq_m/epikong/etape_4/error_and_parse
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Sat Jun 20 05:39:24 2015 Maxime LECOQ
** Last update Sat Jun 20 05:52:23 2015 Maxime LECOQ
*/

#include	"epi.h"

int		go_to_menu_pr(SDL_Event event, t_struct *st, int fl)
{
  if (fl == 1 && event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p)
    {
      menu(st);
      return (1);
    }
  else
    if (fl == 2 && event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p)
      {
	parse_struct(st);
	return (1);
      }
  return (0);
}
