# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 11:22:57 by pandersi          #+#    #+#              #
#    Updated: 2020/07/22 14:57:09 by pandersi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pandersi.filler

SRC = src/ft_filler.c \
		src/place_piece.c \
		src/read_map.c \
		src/read_piece.c

OBJ = $(patsubst %.c, %.o,$(subst src/,,$(SRC)))

LIB = libft/libft.a

INCLUDE = includes/filler.h

all: $(NAME)
.PHONY: all
$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -Wall -Wextra -Werror $(LIB) $(OBJ) -o $(NAME)

.PHONY: clean
clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
