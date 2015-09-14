/*
** go.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 12:03:14 2015 Maxime LECOQ
** Last update Fri Jun 19 22:50:18 2015 Maxime LECOQ
*/

#include	"epi.h"

void		go_rightup(t_struct *st)
{
  if (up_once(st) == 0)
    {
      fct_ptr(st);
      SDL_Flip(st->ecran);
      go_right(st);
      fct_ptr(st);
      SDL_Flip(st->ecran);
      go_right(st);
    }
}

