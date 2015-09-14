/*
** map.c for epi in /home/lecoq_m/epikong/etape_2/error_and_parse
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 02:27:39 2015 Maxime LECOQ
** Last update Thu Jun 18 09:31:06 2015 Maxime LECOQ
*/

#include        "epi.h"

t_ptr           *init_ptrf()
{
  t_ptr         *tab;

  if ((tab = malloc(sizeof(*tab) * 5)) == NULL)
    return (NULL);
  tab[0].ptrf = &level11;
  tab[1].ptrf = &level12;
  tab[2].ptrf = &level13;
  tab[3].ptrf = &level14;
  tab[4].ptrf = &level15;
  return (tab);
}

void            world12(t_struct *st)
{
  t_ptr         *tab;
  int           i;

  tab = init_ptrf();
  i = 0;
  while (i < 5)
    {
      if ((i + 1) == st->map)
        (*tab[i].ptrf)(st);
      i++;
    }
}

t_ptr           *init_ptrf2()
{
  t_ptr         *tab;

  if ((tab = malloc(sizeof(*tab) * 5)) == NULL)
    return (NULL);
  tab[0].ptrf = &level21;
  tab[1].ptrf = &level22;
  tab[2].ptrf = &level23;
  tab[3].ptrf = &level24;
  tab[4].ptrf = &level25;
  return (tab);
}

void            world22(t_struct *st)
{
  t_ptr         *tab;
  int           i;

  tab = init_ptrf2();
  i = 0;
  while (i < 5)
    {
      if ((i + 1) == st->map)
        (*tab[i].ptrf)(st);
      i++;
    }
}

void            map(t_struct *st)
{
  if (st->world_sel == 1)
    world12(st);
  else
    if (st->world_sel == 2)
      world22(st);
    else
      if (st->world_sel == 3)
        world32(st);
}
