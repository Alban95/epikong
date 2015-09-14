/*
** catch_event.c for epi in /home/lecoq_m/epikong/etape_4/error_and_parse
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Sat Jun 20 05:48:16 2015 Maxime LECOQ
** Last update Sat Jun 20 05:54:45 2015 Maxime LECOQ
*/

#include	"epi.h"

void		catch_event(SDL_Event event, t_struct *st)
{
  if (event.key.keysym.sym == SDLK_RIGHT)
    st->world_sel++;
  else
    if (event.key.keysym.sym == SDLK_LEFT)
     st->world_sel--;
}

void		catch_event_map(SDL_Event event, t_struct *st)
{
  if (event.key.keysym.sym == SDLK_RIGHT)
    st->map_sel++;
  else
    if (event.key.keysym.sym == SDLK_LEFT)
     st->map_sel--;
}
