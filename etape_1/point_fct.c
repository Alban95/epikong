/*
** point_fct.c for ptr sur fonction in /home/cloque_b/epikong/etape_1
** 
** Made by alban cloquet
** Login   <cloque_b@epitech.net>
** 
** Started on  Wed Jun 17 20:28:46 2015 alban cloquet
** Last update Wed Jun 17 23:10:46 2015 Maxime LECOQ
*/

#include		"epi.h"

t_ptr			*init_ptr()
{
  t_ptr			*ptr;

  if ((ptr = malloc(sizeof(*ptr) * 9)) == NULL)
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
  return (ptr);
}

int			fct_ptr(t_struct *st)
{
  t_ptr			*ptr;
  int			i;
  int			pt;

  ptr = init_ptr();
  i = 0;
  while (st->file[i])
    {
      if (st->file[i] == '\n')
	{
	  st->pos.x = 0;
	  st->pos.y = st->pos.y + 26;
	}
      else
	{
	  pt = -1;
	  while (++pt < 9)
	    if (ptr[pt].c == st->file[i])
	      (*ptr[pt].ptrf)(st);
	  st->pos.x = st->pos.x + 29;
	}
      i++;
    }
  return (0);
}
