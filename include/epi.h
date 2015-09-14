/*
** rush.h for rush in /home/lecoq_m/BocalEmblem/includes
**
** Made by Maxime LECOQ
** Login   <lecoq_m@epitech.net>
**
** Started on  Fri May 15 21:50:41 2015 Maxime LECOQ
** Last update Sun Jun 21 17:45:08 2015 Maxime LECOQ
*/

#ifndef __EPI_H__
# define __EPI_H__

# include	<SDL/SDL.h>
# include	<SDL/SDL_image.h>
# include	<SDL/SDL_mixer.h>
# include	<SDL/SDL_ttf.h>
# include	<pthread.h>
# include       <stdio.h>
# include       <unistd.h>
# include       <stdlib.h>
# include       <fcntl.h>
# include	"tools.h"
# include	"macro.h"

# define	BUFF_SIZE	16384
# define	BLACK (SDL_Color){0, 0, 0}

typedef struct  s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct  s_heros
{
  int		x;
  int		y;
  int		life;
  int		gun;
  int		fl;
}		t_heros;

typedef struct  s_boss
{
  int		x;
  int		y;
  int		life;
  int		gun;
}		t_boss;

typedef struct  s_struct
{
  char		*name;
  char		*file;
  char		**tab;
  char		**tmap;
  SDL_Rect	pos;
  SDL_Rect	pos2;
  SDL_Surface	*ecran;
  SDL_Surface	*img;
  SDL_Surface	*txt;
  SDL_TimerID	timer;
  SDL_Rect	postxt;
  TTF_Font	*police;
  SDL_Color	color[3];
  int		time;
  int		height;
  int		width;
  int		world;
  int		world_sel;
  int		map;
  int		map_sel;
  int		menu;
  int		end_game;
  int		ok;
  int		key;
  int		end_map;
  t_heros	heros;
  t_boss	boss;
  int		*monster;
  int		turn;
  int		coup;
  int		save;
  int		sound;
  pthread_t	thread;
  Mix_Chunk	*musique;
  Mix_Chunk	*saut;
  Mix_Chunk	*game_over;
  Mix_Chunk	*win;
  Mix_Chunk	*one_up;
  Mix_Chunk	*object;
  Mix_Chunk	*gun;
}		t_struct;

typedef void	(*f)(t_struct *st);

typedef struct	s_ptr
{
  char		c;
  unsigned int	value;
  f		ptrf;
}		t_ptr;

int		error_step1(int ac, char **av, t_struct *st);
int		error_step2(int ac, char **av);
int             first_check(int ac, char **av);
int             check_integer(char *file, char *base);
int             check_largest(char **tab);
int             check_existence(char *map);
char            *put_return(char *str);
int		check_key_door(char *file);
void		place_wall(t_struct *st);
void		place_back(t_struct *st);
void		place_key(t_struct *st);
void		place_s(t_struct *st);
void		place_life(t_struct *st);
void		place_char(t_struct *st);
void		place_monster(t_struct *st);
void		place_gun(t_struct *st);
void            place_door(t_struct *st);
int		fct_ptr(t_struct *st);
int		init_my_sdl(t_struct *st);
int             parse_struct(t_struct *st);
int             world1(t_struct *st);
int             world2(t_struct *st);
int             world3(t_struct *st);
int             parse_struct2(t_struct *st);
void		map(t_struct *st);
int             check_win(SDL_Event event);
int		arrange_struct(int nb, int max);
void            world32(t_struct *st);
void		level11(t_struct *st);
void		level12(t_struct *st);
void		level13(t_struct *st);
void		level14(t_struct *st);
void		level15(t_struct *st);
void		level21(t_struct *st);
void		level22(t_struct *st);
void		level23(t_struct *st);
void		level24(t_struct *st);
void		level25(t_struct *st);
void		level31(t_struct *st);
void		level32(t_struct *st);
void		level33(t_struct *st);
void		level34(t_struct *st);
void		level35(t_struct *st);
int		menu(t_struct *st);
int		execute(t_struct *st);
char            *have_name_begin(t_struct *st);
int             execute_map(t_struct *st);
void            pausa(t_struct *st);
void		write_in_conf_file(t_struct *st);
int             write_in_conf_level(t_struct *st);
int             map_not_end(t_struct *st);
void            go_rightup(t_struct *st);
void            go_leftup(t_struct *st);
void            go_left(t_struct *st);
void            go_right(t_struct *st);
void            go_down(t_struct *st);
void            go_up(t_struct *st);
int             init_heros(t_struct *st);
int             up_once(t_struct *st);
int             up_once2(t_struct *st);
int		check_scale(t_struct *st);
int		check_up(t_struct *st);
int		check_door(t_struct *st);
char            **change_bad_char(char **tab, char **tab2);
int             check_scale2(t_struct *st);
int		gravity(t_struct *st);
int		aff_my_level(t_struct *st);
int             init_monster(t_struct *st);
int             move_monster(t_struct *st);
t_pos           find_pos(char **tab, int wait);
void		free_struct(t_struct *st);
void		go_to_menu(t_struct *st);
char            **change_bad_char(char **tab, char **tab2);
int		put_life(t_struct *st);
int             have_struct_map(t_struct *st);
char            *have_name_map(t_struct *st);
int             game_over(t_struct *st);
int             check_end_map(t_struct *st, int life);
void		take(t_struct *st);
char            **change_key(t_struct *st);
void		check_bloquant(char c, int fl, t_struct *st);
int             gravity_monster(t_struct *st);
char            **change_key(t_struct *st);
Uint32          aff_time(Uint32 intervalle, void *param);
int		init_map_game(t_struct *st);
void		place_ball(t_struct *st);
void            shoot_left(t_struct *st);
void            shoot_right(t_struct *st);
int             check_char(char c);
char            check_wich(char **tab, int y, int x);
int		error_boss(char *map);
int		run_boss_map(t_struct *st);
int             init_heros_boss(t_struct *st);
void            place_boss(t_struct *st);
int             init_struct_boss(t_struct *st);
int             init_boss(t_struct *st);
int             run_boss(t_struct *st);
char            check_wich_4(char **tab, int y, int x, t_struct *st);
int             init_struct_boss(t_struct *st);
void		aff_rules(t_struct *st);
int             check_tab(char **tab);
void            catch_signal(t_struct *st);
void            find_turn(t_struct *st);
int		shoot_boss(t_struct *st);
int		check_gun(t_struct *st);
int             gravity_boss(t_struct *st);
int		move_lateral(t_struct *st);
int             boss_turn(t_struct *st);
int             move_right(t_struct *st);
int             move_left(t_struct *st);
int             check_valid_case_sol(char c);
int             check_valid_case(char c);
int		check_scale_boss(t_struct *st);
int		go_to_menu_pr(SDL_Event event, t_struct *st, int fl);
void		catch_event(SDL_Event event, t_struct *st);
void            catch_event_map(SDL_Event event, t_struct *st);
int		check_conf_file();
int             put_life_b(t_struct *st);

#endif /* !__EPI_H__ */
