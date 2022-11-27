# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 21:09:27 by mmatsuo           #+#    #+#              #
#    Updated: 2022/11/27 21:09:28 by mmatsuo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	cc
#CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I include

SRCS		=	src/display.c src/input.c src/calc.c src/main.c
OBJS		=	$(SRCS:%.c=$(OBJDIR)/%.o)
LIBMLX		=	libmlx.dylib
OBJDIR		=	objs

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) -o $(NAME)

$(OBJDIR)/%.o:%.c
			@mkdir -p $(@D)
			$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

clean:
		rm -rf $(OBJDIR)
		make fclean -C libft

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re