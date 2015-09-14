/*
** change_bad_param.c for ef in /home/lecoq_m/epikong/etape_3/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 18:22:49 2015 Maxime LECOQ
** Last update Thu Jun 18 18:29:25 2015 Maxime LECOQ
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
          if (tab2[i][x] == 's' || tab2[i][x] == 'o')
            {
              if (tab[i][x] != 'i'
                  && tab[i][x] != 'm')
                tab[i][x] = tab2[i][x];
            }
	}
    }
  return (tab);
}
