# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 11:21:24 by sesim             #+#    #+#              #
#    Updated: 2022/07/17 00:46:06 by sesim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

SRCS = fdf.c \
	   map_parser_1.c \
	   map_parser_2.c \
	   map_parser_3.c \
	   anti_aliasing_1.c \
	   anti_aliasing_2.c \
	   anti_aliasing_3.c \
	   anti_aliasing_utils.c \
	   bresen_1.c \
	   bresen_2.c \
	   euler_angle.c \
	   projection.c \
	   liner.c \
	   liner_utils.c \
	   key_func_1.c \
	   key_func_2.c


OBJS = $(SRCS:.c=.o)

NAME = fdf

all : $(NAME)

fdf: $(OBJS)
#	make -C ../mlx
	$(CC) $(CFLAGS) -L ../libft -l ft -L ../mlx -l mlx -framework OpenGL -framework AppKit $^ -o $@

clean :
#	make -C ../mlx clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : fdf all clean fclean re
