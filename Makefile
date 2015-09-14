##
## Makefile for epi in /home/lecoq_m/epikong
##
## Made by Maxime LECOQ
## Login   <lecoq_m@epitech.net>
##
## Started on  Wed Jun 17 11:43:35 2015 Maxime LECOQ
## Last update Sun Jun 21 17:51:44 2015 Maxime LECOQ
##

NAME1= 		epikong_etape_1

STEP1=		etape_1/


SRC1=		$(STEP1)main.c				\
		$(STEP1)fonction_pointeur2.c		\
		$(STEP1)fonction_pointeur.c		\
		$(STEP1)point_fct.c			\
		$(STEP1)init_sdl.c			\
							\
		$(STEP1)error/error.c			\

OBJ1=		$(SRC1:.c=.o)

NAME2= 		epikong_etape_2

STEP2=		etape_2/


SRC2=		$(STEP2)main.c				\
		$(STEP2)init_sdl.c			\
							\
		$(STEP2)execute/execute.c		\
		$(STEP2)execute/execute_map.c		\
		$(STEP2)execute/write_in_conf_file.c	\
		$(STEP2)execute/go.c			\
		$(STEP2)execute/go2.c			\
		$(STEP2)execute/map_not_end.c		\
		$(STEP2)execute/init_char.c		\
		$(STEP2)execute/check_up.c		\
		$(STEP2)execute/check_down.c		\
		$(STEP2)execute/gravity.c		\
		$(STEP2)execute/move_monster.c		\
		$(STEP2)execute/find_pos.c		\
							\
		$(STEP2)aff/menu.c			\
		$(STEP2)aff/fonction_pointeur2.c	\
		$(STEP2)aff/fonction_pointeur.c		\
		$(STEP2)aff/point_fct.c			\
		$(STEP2)aff/aff.c			\
							\
		$(STEP2)error_and_parse/error.c		\
		$(STEP2)error_and_parse/first_check.c	\
		$(STEP2)error_and_parse/parse_struct.c	\
		$(STEP2)error_and_parse/world.c		\
		$(STEP2)error_and_parse/parse_struct2.c	\
		$(STEP2)error_and_parse/map.c		\
		$(STEP2)error_and_parse/map2.c		\
		$(STEP2)error_and_parse/level1.c	\
		$(STEP2)error_and_parse/level2.c	\
		$(STEP2)error_and_parse/level3.c	\
		$(STEP2)execute/go_to_menu.c		\
		$(STEP2)execute/change_bad_char.c	\
		$(STEP2)error_and_parse/check_cf_file.c	\

OBJ2=		$(SRC2:.c=.o)

NAME3= 		epikong_etape_3

STEP3=		etape_3/


SRC3=		$(STEP3)main.c				\
		$(STEP3)init_sdl.c			\
							\
		$(STEP3)execute/execute.c		\
		$(STEP3)execute/execute_map.c		\
		$(STEP3)execute/write_in_conf_file.c	\
		$(STEP3)execute/go.c			\
		$(STEP3)execute/go2.c			\
		$(STEP3)execute/map_not_end.c		\
		$(STEP3)execute/map_not_end2.c		\
		$(STEP3)execute/init_char.c		\
		$(STEP3)execute/check_up.c		\
		$(STEP3)execute/check_down.c		\
		$(STEP3)execute/gravity.c		\
		$(STEP3)execute/gravity2.c		\
		$(STEP3)execute/move_monster.c		\
		$(STEP3)execute/find_pos.c		\
		$(STEP3)execute/go_to_menu.c		\
		$(STEP3)execute/change_bad_char.c	\
		$(STEP3)execute/life.c			\
		$(STEP3)execute/take.c			\
		$(STEP3)execute/my_time.c		\
							\
		$(STEP3)aff/menu.c			\
		$(STEP3)aff/fonction_pointeur2.c	\
		$(STEP3)aff/fonction_pointeur.c		\
		$(STEP3)aff/point_fct.c			\
		$(STEP3)aff/aff.c			\
							\
		$(STEP3)error_and_parse/error.c		\
		$(STEP3)error_and_parse/first_check.c	\
		$(STEP3)error_and_parse/parse_struct.c	\
		$(STEP3)error_and_parse/world.c		\
		$(STEP3)error_and_parse/parse_struct2.c	\
		$(STEP3)error_and_parse/map.c		\
		$(STEP3)error_and_parse/map2.c		\
		$(STEP3)error_and_parse/level1.c	\
		$(STEP3)error_and_parse/level2.c	\
		$(STEP3)error_and_parse/level3.c	\
		$(STEP3)error_and_parse/check_cf_file.c	\

OBJ3=		$(SRC3:.c=.o)

NAME4= 		epikong_etape_4

STEP4=		etape_4/

SRC4=		$(STEP4)main.c				\
		$(STEP4)init_sdl.c			\
							\
		$(STEP4)execute/execute.c		\
		$(STEP4)execute/execute_map.c		\
		$(STEP4)execute/write_in_conf_file.c	\
		$(STEP4)execute/go.c			\
		$(STEP4)execute/go2.c			\
		$(STEP4)execute/map_not_end.c		\
		$(STEP4)execute/map_not_end2.c		\
		$(STEP4)execute/init_char.c		\
		$(STEP4)execute/check_up.c		\
		$(STEP4)execute/check_down.c		\
		$(STEP4)execute/gravity.c		\
		$(STEP4)execute/gravity2.c		\
		$(STEP4)execute/move_monster.c		\
		$(STEP4)execute/find_pos.c		\
		$(STEP4)execute/go_to_menu.c		\
		$(STEP4)execute/change_bad_char.c	\
		$(STEP4)execute/life.c			\
		$(STEP4)execute/take.c			\
		$(STEP4)execute/my_time.c		\
		$(STEP4)execute/shoot_left.c		\
		$(STEP4)execute/shoot_right.c		\
							\
		$(STEP4)aff/menu.c			\
		$(STEP4)aff/fonction_pointeur.c		\
		$(STEP4)aff/fonction_pointeur2.c	\
		$(STEP4)aff/fonction_pointeur3.c	\
		$(STEP4)aff/point_fct.c			\
		$(STEP4)aff/aff.c			\
							\
		$(STEP4)error_and_parse/error.c		\
		$(STEP4)error_and_parse/error_boss.c	\
		$(STEP4)error_and_parse/first_check.c	\
		$(STEP4)error_and_parse/parse_struct.c	\
		$(STEP4)error_and_parse/world.c		\
		$(STEP4)error_and_parse/parse_struct2.c	\
		$(STEP4)error_and_parse/map.c		\
		$(STEP4)error_and_parse/map2.c		\
		$(STEP4)error_and_parse/level1.c	\
		$(STEP4)error_and_parse/level2.c	\
		$(STEP4)error_and_parse/level3.c	\
		$(STEP4)error_and_parse/go_to_menu.c	\
		$(STEP4)error_and_parse/catch_event.c	\
		$(STEP4)error_and_parse/check_cf_file.c	\
							\
		$(STEP4)boss/boss_map.c			\
		$(STEP4)boss/init_boss.c		\
		$(STEP4)boss/boss.c			\
		$(STEP4)boss/boss_shoot.c		\
		$(STEP4)boss/gravity_b.c		\
		$(STEP4)boss/move_left.c		\
		$(STEP4)boss/move_right.c		\
		$(STEP4)boss/move_scale.c		\
		$(STEP4)boss/valid_case.c		\
		$(STEP4)boss/put_life_b.c		\

OBJ4=		$(SRC4:.c=.o)

TOOLS=		tools/

SRC_T=		$(TOOLS)delete_list.c			\
		$(TOOLS)get_next_line.c			\
		$(TOOLS)get_file_content.c		\
		$(TOOLS)my_list.c			\
		$(TOOLS)my_list2.c			\
		$(TOOLS)my_str_to_wordtab.c		\
		$(TOOLS)put_color.c			\
		$(TOOLS)put_color2.c			\
		$(TOOLS)tools.c				\
		$(TOOLS)tools2.c			\
		$(TOOLS)tools3.c			\
		$(TOOLS)tools4.c			\
		$(TOOLS)tools5.c			\
		$(TOOLS)tools6.c			\
		$(TOOLS)tools7.c			\
		$(TOOLS)tools8.c			\

OBJT=		$(SRC_T:.c=.o)

CC=		cc

CFLAGS=		-I./include/				\
		-Wall					\
		-Werror					\

RM=		rm -rf

SDL=		`sdl-config --cflags --libs`			\
		`pkg-config --cflags --libs SDL_image SDL_ttf`	\
		  -lSDL_mixer

all:		$(NAME1) $(NAME2) $(NAME3) $(NAME4)

$(NAME1):	$(OBJ1) $(OBJT)
	$(CC) $(SDL) -o $(NAME1) $(OBJ1) $(OBJT)

$(NAME2):	$(OBJ2) $(OBJT)
	$(CC) $(SDL) -o $(NAME2) $(OBJ2) $(OBJT)

$(NAME3):	$(OBJ3) $(OBJT)
	$(CC) $(SDL) -o $(NAME3) $(OBJ3) $(OBJT)

$(NAME4):	$(OBJ4) $(OBJT)
	$(CC) $(SDL) -o $(NAME4) $(OBJ4) $(OBJT)

clean:
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)
	$(RM) $(OBJ3)
	$(RM) $(OBJ4)
	$(RM) $(OBJT)

fclean	:	clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)
	$(RM) $(NAME3)
	$(RM) $(NAME4)

re:		fclean all

1:		$(NAME1)

2:		$(NAME2)

3:		$(NAME3)

4:		$(NAME4)
