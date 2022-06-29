# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 09:25:04 by sesim             #+#    #+#              #
#    Updated: 2022/06/28 09:25:07 by sesim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = pixel.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

all : $(NAME)

fdf: $(OBJS)
	make -C ../mlx
	$(CC) $(CLFAGS) -L ../mlx -l mlx -framework OpenGL -framework AppKit $^ -o $@

clean :
	make -C ../mlx clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : fdf all clean fclean re
