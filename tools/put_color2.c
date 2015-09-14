/*
** put_color.c for lem in /home/lecoq_m/abc/lur_in/src/tools
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Sat May  2 16:02:20 2015 Maxime LECOQ
** Last update Wed Jun 17 11:40:18 2015 Maxime LECOQ
*/

#include	"epi.h"

void		put_blue(char *str)
{
  puterror("\033[34;01m");
  puterror(str);
  puterror("\033[0m");
}
