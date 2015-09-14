/*
** my_list.c for epi in /home/lecoq_m/epikong/src/tools
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Wed Jun 17 11:39:23 2015 Maxime LECOQ
** Last update Wed Jun 17 11:40:01 2015 Maxime LECOQ
*/

#include	"epi.h"

t_list		*create_list(void)
{
  t_list	*root;

  if ((root = malloc(sizeof(*root))) != NULL)
    {
      root->prev = root;
      root->next = root;
    }
  return (root);
}

void		my_show_list_right_to_left(t_list *root)
{
  t_list	*r_l;

  r_l = root->next;
  while (r_l != root)
    {
      my_putstr(r_l->str);
      r_l = r_l->next;
    }
}

void		my_show_list_left_to_right(t_list *root)
{
  t_list	*l_r;

  l_r = root->prev;
  while (l_r != root)
    {
      my_putstr(l_r->str);
      l_r = l_r->prev;
    }
}

void		add_before_val(t_list *element, char *str)
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) != NULL)
    {
      new->str = str;
      new->prev = element->prev;
      new->next = element;
      element->prev->next = new;
      element->prev = new;
    }
}

void		add_after_val(t_list *element, char *str)
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) != NULL)
    {
      new->str = str;
      new->prev = element;
      new->next = element->next;
      element->next->prev = new;
      element->next = new;
    }
}
