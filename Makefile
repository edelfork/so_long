# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 18:40:16 by gimartin          #+#    #+#              #
#    Updated: 2022/02/24 18:44:55 by gimartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = *.c my_lib/gnl/*.c my_lib/libft/*.c srcs/*.c

MIN = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Werror -Wextra -Wall -g -o
CC = gcc
OBJ = $(SRC:.=.o)

$(NAME):
	$(CC) $(SRC) $(MIN) $(FLAGS) $(NAME)

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
