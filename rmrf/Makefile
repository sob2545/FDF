# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 11:21:24 by sesim             #+#    #+#              #
#    Updated: 2022/07/17 00:45:42 by sesim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

SRCS = fdf.c \
	   map_parser_1.c \
	   map_parser_2.c \
	   map_parser_3.c \
	   bresenham_1.c \
	   bresenham_2.c \
	   rotation.c \
	   projection.c \
	   liner.c \
	   key_func1.c \
	   key_func2.c


OBJS = $(SRCS:.c=.o)

NAME = fdf

all : $(NAME)

fdf: $(OBJS)
#	make -C ../mlx
	$(CC) $(CFLAGS) -L ../libft -l ft -L ../mlx -l mlx -framework OpenGL -framework AppKit $^ -o $@

test :
	$(CC) -L ../libft -l ft -L ../mlx -l mlx -framework OpenGL -framework AppKit *.c

clean :
#	make -C ../mlx clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : fdf all clean fclean re
