# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlux <tlux@42.fr>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 06:20:44 by tlux              #+#    #+#              #
#    Updated: 2018/02/09 18:55:31 by tlux             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

NAME = lem-in
HEADER = lem_in.h
LIB = libft/libft.a
SRC = parser.c start_distance.c find_paths.c resolve.c errors.c add_func.c

OBJ = $(addprefix solver/, $(SRC:.c=.o))

CC = gcc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)

$(NAME) : $(OBJ) $(HEADER)
	make -C libft
	$(CC) $(FLAGS) $(LIB) $(OBJ) -o $(NAME)

clean :
	make -C libft clean
	@rm -rf $(OBJ)

fclean :	clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all
