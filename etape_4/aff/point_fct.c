/*
** point_fct.c for ptr sur fonction in /home/cloque_b/epikong/etape_1
** 
** Made by alban cloquet
** Login   <cloque_b@epitech.net>
** 
** Started on  Wed Jun 17 20:28:46 2015 alban cloquet
** Last update Sat Jun 20 02:18:19 2015 Maxime LECOQ
*/

#include		"epi.h"

t_ptr			*init_ptr()
{
  t_ptr			*ptr;

  if ((ptr = malloc(sizeof(*ptr) * 11)) == NULL)
    return (NULL);
  ptr[0].c = 'w';
  ptr[0].ptrf = &place_wall;
  ptr[1].c = '.';
  ptr[1].ptrf = &place_back;
  ptr[2].c = 'k';
  ptr[2].ptrf = &place_key;
  ptr[3].c = 's';
  ptr[3].ptrf = &place_s;
  ptr[4].c = 'i';
  ptr[4].ptrf = &place_char;
  ptr[5].c = 'm';
  ptr[5].ptrf = &place_monster;
  ptr[6].c = 'l';
  ptr[6].ptrf = &place_life;
  ptr[7].c = 'g';
  ptr[7].ptrf = &place_gun;
  ptr[8].c = 'o';
  ptr[8].ptrf = &place_door;
  ptr[9].c = 'e';
  ptr[9].ptrf = &place_ball;
  return (ptr);
}

int			fct_ptr(t_struct *st)
{
  t_ptr			*ptr;
  int			i;
  int			pt;
  int			a;

  ptr = init_ptr();
  ptr[10].c = 'b';
  ptr[10].ptrf = &place_boss;
  i = -1;
  st->pos.y = 0;
  while (st->tmap[++i])
    {
      a = -1;
      st->pos.x = 0;
      while (st->tmap[i][++a])
	{
	  pt = -1;
	  while (++pt < 11)
	    if (ptr[pt].c == st->tmap[i][a])
	      (*ptr[pt].ptrf)(st);
	  st->pos.x = st->pos.x + 29;
	}
      st->pos.y = st->pos.y + 26;
    }
  return (0);
}
