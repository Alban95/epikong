/*
** change_bad_param.c for ef in /home/lecoq_m/epikong/etape_3/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 18:22:49 2015 Maxime LECOQ
** Last update Fri Jun 19 10:19:24 2015 Maxime LECOQ
*/

#include	"epi.h"

char            **change_bad_char(char **tab, char **tab2)
{
  int           i;
  int           x;

  i = -1;
  while (tab[++i])
    {
      x = -1;
      while (tab[i][++x])
        {
          if (tab2[i][x] == 's' || tab2[i][x] == 'o'
	      || tab2[i][x] == 'k' || tab2[i][x] == 'g'
	      || tab2[i][x] == 'l')
            {
              if (tab[i][x] != 'i'
                  && tab[i][x] != 'm')
                tab[i][x] = tab2[i][x];
            }
	}
    }
  return (tab);
}

char            **change_key(t_struct *st)
{
  int           i;
  int           y;

  i = 0;
  while (st->tab[i])
    {
      y = 0;
      while (st->tab[i][y])
        {
          if (st->tab[i][y] == 'k')
            {
              st->tab[i][y] = '.';
              return (st->tab);
            }
          y++;
        }
      i++;
    }
  return (st->tab);
}
