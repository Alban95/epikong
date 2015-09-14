/*
** delete_list.c for epi in /home/lecoq_m/epikong/src/tools
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Wed Jun 17 11:37:50 2015 Maxime LECOQ
** Last update Wed Jun 17 11:38:01 2015 Maxime LECOQ
*/

#include	"epi.h"

void            delete_val(t_list *element)
{
  element->prev->next = element->next;
  element->next->prev = element->prev;
  free(element);
}

void            empty_list(t_list * list)
{
  t_list        *l_r;
  t_list        *del_next;

  l_r = list->next;
  while (l_r != list)
    {
      del_next = l_r->next;
      free(l_r);
      l_r = del_next;
    }
}

void            delete_list(t_list **list)
{
  empty_list(*list);
  free(*list);
  *list = NULL;
}
