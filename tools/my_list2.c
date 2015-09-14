/*
** my_list2.c for lem in /home/lecoq_m/abc/lur_in
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Fri May  1 18:46:47 2015 Maxime LECOQ
** Last update Wed Jun 17 11:39:14 2015 Maxime LECOQ
*/

#include	"epi.h"

int	list_size(t_list *way, t_list *root)
{
  int	i;

  i = 0;
  way = root->prev;
  while (way != root)
    {
      way = way->prev;
      i++;
    }
  return (i);
}
