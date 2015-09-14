/*
** valid_case.c for epi in /home/lecoq_m/epikong/etape_4/boss
** 
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
** 
** Started on  Sat Jun 20 04:33:37 2015 Maxime LECOQ
** Last update Sat Jun 20 04:33:39 2015 Maxime LECOQ
*/

#include        "epi.h"

int             check_valid_case(char c)
{
  if (c == '.' || c == 'l' || c == 's' || c == 'g')
    return (1);
  else
    return (-1);
}

int             check_valid_case_sol(char c)
{
  if (c == 'w' || c == 's' || c== 'm')
    return (1);
  else
    return (-1);
}
