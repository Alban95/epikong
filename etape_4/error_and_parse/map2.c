/*
** map.c for epi in /home/lecoq_m/epikong/etape_2/error_and_parse
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 02:27:39 2015 Maxime LECOQ
** Last update Thu Jun 18 09:31:12 2015 Maxime LECOQ
*/

#include        "epi.h"

t_ptr		*init_ptrf3()
{
  t_ptr		*tab;

  if ((tab = malloc(sizeof(*tab) * 5)) == NULL)
    return (NULL);
  tab[0].ptrf = &level31;
  tab[1].ptrf = &level32;
  tab[2].ptrf = &level33;
  tab[3].ptrf = &level34;
  tab[4].ptrf = &level35;
  return (tab);
}

void		world32(t_struct *st)
{
  t_ptr		*tab;
  int		i;

  tab = init_ptrf3();
  i = 0;
  while (i < 5)
    {
      if ((i + 1) == st->map)
	(*tab[i].ptrf)(st);
      i++;
    }
}
