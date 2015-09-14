/*
** find_pos.c for de in /home/lecoq_m/epikong/etape_2/execute
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Thu Jun 18 15:59:34 2015 Maxime LECOQ
** Last update Thu Jun 18 17:19:51 2015 Maxime LECOQ
*/

#include	"epi.h"

t_pos           find_pos(char **tab, int wait)
{
  t_pos         pos;
  int           tmp;

  pos.y = 0;
  tmp = 0;
  while (tab[pos.y])
    {
      pos.x = 0;
      while (tab[pos.y][pos.x])
        {
          if (tab[pos.y][pos.x] == 'm')
            {
              if (tmp == wait)
                return (pos);
              else
                tmp++;
            }
          pos.x++;
        }
      pos.y++;
    }
  pos.y = -42;
  return (pos);
}
