/*
** go.c for epi in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 12:03:14 2015 Maxime LECOQ
** Last update Thu Jun 18 14:28:41 2015 Maxime LECOQ
*/

#include	"epi.h"

void		go_rightup(t_struct *st)
{
  if (up_once(st) == 0)
    {
      go_right(st);
      go_right(st);
    }
}

