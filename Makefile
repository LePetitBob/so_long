# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 16:02:55 by vduriez           #+#    #+#              #
#    Updated: 2022/01/21 16:36:20 by vduriez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang

CFLAGS = -Wall -Wextra -Werror -g
FSANITIZE = -fsanitize=address -fsanitize=undefined -g3

INCLUDE = -Lminilibx -lmlx -lX11 -lXext -lm

SRC =	srcs/exits.c				\
		srcs/map_check.c			\
		srcs/get_map.c				\
		srcs/get_next_line.c		\
		srcs/get_next_line_utils.c	\
		srcs/set_images.c			\
		srcs/set_screen.c			\
		srcs/moves.c				\
		srcs/ft_itoa.c				\
		srcs/display_moves.c		\
		srcs/main.c					

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./includes/so_long.h
	make -C ./minilibx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE)

fsanitize: $(OBJ) ./includes/so_long.h
	make -C ./minilibx
	$(CC) $(CFLAGS) $(FSANITIZE) -o $(NAME)_fsanitize $(OBJ) $(INCLUDE)

clean:
	make -C ./minilibx clean
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME)_fsanitize

re: fclean all

.PHONY: all clean fclean re
