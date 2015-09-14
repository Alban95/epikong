/*
** tools8.c for lem in /home/lecoq_m/abc/lur_in/src/parsing
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Wed Apr 15 17:37:26 2015 Maxime LECOQ
** Last update Thu Jun 18 00:39:03 2015 Maxime LECOQ
*/

#include        "epi.h"

int     my_tabcmp(char **tab, char **tab2)
{
  int   i;

  if (tab == NULL || tab2 == NULL
      || tablen(tab) != tablen(tab2))
    return (-1);
  i = 0;
  while (tab[i])
    {
      if (my_strcmp(tab[i], tab2[i]) != 0)
        return (1);
      i++;
    }
  return (0);
}

char	**tabcpy(char **tab)
{
  char	**tab2;
  int	i;

  if ((tab2 = malloc(sizeof(char *) * (tablen(tab) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (tab[i])
    {
      tab2[i] = my_strdup(tab[i]);
      i++;
    }
  tab2[i] = NULL;
  return (tab2);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
