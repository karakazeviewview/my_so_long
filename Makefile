# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 21:09:27 by mmatsuo           #+#    #+#              #
#    Updated: 2022/12/08 01:53:58by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	src/calc.c				\
				src/display.c   		\
				src/check_map.c 		\
				src/check_playable.c	\
				src/error.c				\
				src/init.c				\
				src/input.c				\
				src/main.c				\
				src/utils.c

OBJS		=	$(SRCS:%.c=$(OBJDIR)/%.o)

OS			=	$(shell uname)

ifeq ($(OS), Linux)
MLXDIR		=	minilibx-linux
MLXFLAGS	=	-L$(MLXDIR) -lmlx -lXext -lX11
else
MLXDIR		=	minilibx_mms_20200219/
MLXFLAGS	=	$(MLXDIR)/libmlx.dylib
endif

INCLUDE		=	-I $(MLXDIR)

OBJDIR		=	objs

all:	$(NAME)

$(NAME):	$(OBJS)
			@make -C $(MLXDIR)
			$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o:%.c
			@mkdir -p $(@D)
			$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

# Map files
TEST_MAP_SRCS :=	T00_basic1.ber \
					T01_basic2.ber \
					T02_smallest.ber \
					T03_largest.ber 

ERROR_MAP_SRCS :=	E00_empty.ber \
					E01_not_closed.ber \
					E02_not_closed2.ber \
					E03_no_collectible.ber \
					E05_no_spawn.ber \
					E06_from_second_line.ber \
					E07_not_rectangle.ber \
					E08_void_line.ber \
					E09_too_large.ber \
					E11_wrong_char.ber \
					E12_void_first_line.ber

ERROR_MAP_SRCS_yshimoda :=	map_yshimoda/f_map00_name_error.berr	\
							map_yshimoda/f_map02_two_P.ber	\
							map_yshimoda/f_map03_zero_C.ber	\
							map_yshimoda/f_map04_zero_E.ber	\
							map_yshimoda/f_map05_zero_P.ber	\
							map_yshimoda/f_map06_blank_map.ber	\
							map_yshimoda/f_map07_not_rect.ber	\
							map_yshimoda/f_map08_top_blank_line.ber	\
							map_yshimoda/f_map09_bottom_blank_line.ber	\
							map_yshimoda/f_map10_middle_blank_line.ber	\
							map_yshimoda/f_map15_middle_of_the_top_row.ber	\
							map_yshimoda/f_map16_middle_of_the_bottom_row.ber	\
							map_yshimoda/f_map17_middle_of_the_left_column.ber	\
							map_yshimoda/f_map18_middle_of_the_right_column.ber	\
							map_yshimoda/f_map19_one_line.ber	\
							map_yshimoda/f_map20_two_line.ber	\
							map_yshimoda/f_map23_cannot_collect_c.ber

MAP_DIR := maps/
TEST_MAPS := ${addprefix ${MAP_DIR},${TEST_MAP_SRCS}}
ERROR_MAPS := ${addprefix ${MAP_DIR},${ERROR_MAP_SRCS}}

# Debug commands
play: all
	@for map in ${TEST_MAPS} ; \
	do ./${NAME} $$map ; done
	@echo "----finish----"

dev: all
	@for emap in ${ERROR_MAPS} ; do \
	# cat $$emap ; echo "\n" ; \
	./${NAME} $$emap ; done
	@echo "----finish----"

yshimoda: all
	@for emap in ${ERROR_MAP_SRCS_yshimoda} ; do \
	# cat $$emap ; echo "\n" ; \
	echo $$emap; \
	./${NAME} $$emap ; done
	@echo "----finish----"

clean:
		make clean -C ${MLXDIR} --no-print-directory
		${RM} -r $(OBJDIR)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
