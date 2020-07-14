# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 11:22:57 by pandersi          #+#    #+#              #
#    Updated: 2020/07/14 11:56:05 by pandersi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pandersi.filler

SRC = src/..

OBJ = $(patsubst %.c, %.o, $(SRC))

LIB = libft/libft.a

INCLUDE = filler.h

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
