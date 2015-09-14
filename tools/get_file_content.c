/*
** get_file_content.c for lib in /home/lecoq_m/my_func
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Tue Jan  6 10:18:31 2015 Maxime LECOQ
** Last update Wed Jun 17 11:38:45 2015 Maxime LECOQ
*/

#include        "epi.h"

char	*my_concat(char *src, char *str)
{
  char	*end;
  int	i;
  int	x;

  if ((end = malloc(sizeof(char *) *
		    my_strlen(src) + my_strlen(str) + 1)) == NULL)
    return (NULL);
  x = 0;
  i = 0;
  while (src[i])
    {
      end[i] = src[i];
      i++;
    }
  while (str[x])
    {
      end[i] = str[x];
      i++;
      x++;
    }
  end[i] = '\0';
  if (src[0] != '\0')
    free(src);
  return (end);
}

int	check_file(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 7 && str[i] <= 13) || (str[i] >= 32 && str[i] <= 126))
	i++;
      else
	{
	  puterror("ERROR: file isn't valid.\n");
	  return (-1);
	}
    }
  return (1);
}

char	*get_file_content(char *filename)
{
  int   fd;
  char  buffer[8192];
  char	*final;
  int   nblu;

  final = "";
  if ((fd = open(filename, O_RDWR)) == -1)
    {
      puterror("ERROR: this file name does not exist.\n");
      return (NULL);
    }
  while ((nblu = read(fd, buffer, 8191)) > 0)
    {
      buffer[nblu] = '\0';
      if ((final[0] == '\0' && check_file(buffer) == - 1)
	  || (final = my_concat(final, buffer)) == NULL)
	return (NULL);
    }
  close(fd);
  if (final[0] == '\0')
    {
      puterror("ERROR: File exists, but is empty.\n");
      return (NULL);
    }
  return (final);
}
