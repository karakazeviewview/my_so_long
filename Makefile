# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 21:09:27 by mmatsuo           #+#    #+#              #
#    Updated: 2022/12/04 12:23:18 by mmatsuo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	cc -g
#CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I include

SRCS		=	src/display.c src/input.c src/calc.c src/main.c src/init.c src/check_map.c
OBJS		=	$(SRCS:%.c=$(OBJDIR)/%.o)
LIBMLX		=	libmlx.dylib
OBJDIR		=	objs

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) -o $(NAME)

$(OBJDIR)/%.o:%.c
			@mkdir -p $(@D)
			$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

# Map files
TEST_MAP_SRCS := T00_basic1.ber \
				T01_basic2.ber \
				T02_smallest.ber \
				T03_largest.ber 
ERROR_MAP_SRCS := E00_empty.ber \
				E01_not_closed.ber \
				E02_not_closed2.ber \
				E03_no_collectible.ber \
				E05_no_spawn.ber \
				E06_from_second_line.ber \
				E07_not_rectangle.ber \
				E08_void_line.ber \
				E09_too_large.ber \
				E11_wrong_char.ber \
				E12_void_first_line.ber \
				.ber

MAP_DIR := maps/
TEST_MAPS := ${addprefix ${MAP_DIR},${TEST_MAP_SRCS:.c=.o}}
ERROR_MAPS := ${addprefix ${MAP_DIR},${ERROR_MAP_SRCS:.c=.o}}

# Debug commands
play: all
	@for map in ${TEST_MAPS} ; \
	do ./${NAME} $$map ; done
	@echo "----finish----"

dev: all
	@for emap in ${ERROR_MAPS} ; \
	do ./${NAME} $$emap ; done
	@echo "----finish----"

clean:
		rm -rf $(OBJDIR)
		make fclean -C libft

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re