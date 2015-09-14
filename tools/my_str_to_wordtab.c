/*
** my_str_to_wordtab.c for epi in /home/lecoq_m/epikong/src/tools
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Wed Jun 17 11:39:40 2015 Maxime LECOQ
** Last update Wed Jun 17 11:39:45 2015 Maxime LECOQ
*/

#include	"epi.h"

int		my_count_word(char *str, char c)
{
  int		i;
  int		j;
  int		word;

  i = 0;
  j = 0;
  word = 0;
  while (str[i])
    {
      while (str[i] == c)
	i++;
      while (str[i] != c && str[i] != '\0')
	{
	  i++;
	  j = 1;
	}
      if (j == 1)
	{
	  word++;
	  j = 0;
	}
    }
  return (word);
}

int		my_word_len(char *str, int pos, char c)
{
  int		len;

  len = 0;
  while (str[pos] != c && str[pos] != '\0')
    {
      pos++;
      len++;
    }
  return (len);
}

char		*copy_to_tab(char *dest, char *src, int pos, char c)
{
  int		i;

  i = 0;
  if ((dest = malloc(sizeof(char) * (my_word_len(src, pos, c) + 1))) == NULL)
    return (NULL);
  while (src[pos] != c && src[pos] != '\0')
    {
      dest[i] = src[pos];
      i++;
      pos++;
    }
  dest[i] = 0;
  return (dest);
}

char		**my_str_to_wordtab(char *str, char c)
{
  int		i;
  int		j;
  char		**tmp;

  i = 0;
  j = 0;
  if ((tmp = malloc(sizeof(char *) * (my_count_word(str, c) + 2))) == NULL)
    return (NULL);
  while (str[i])
    {
      while (str[i] == c)
	i++;
      if (str[i] != 0)
	{
	  if ((tmp[j] = copy_to_tab(tmp[j], str, i, c)) == NULL)
	    return (NULL);
	  j++;
	}
      while (str[i] && str[i] != c)
	i++;
    }
  tmp[j] = NULL;
  return (tmp);
}
