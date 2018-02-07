# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlux <tlux@42.fr>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 06:20:44 by tlux              #+#    #+#              #
#    Updated: 2018/02/07 22:00:45 by tlux             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

NAME = libft/libft.a
HEADER = lem_in.h
EXEC = lem-in
SRC = parser.c start_distance.c find_paths.c resolve.c errors.c add_func.c

OBJ = $(addprefix solver/, $(SRC:.c=.o))

CC = gcc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)

$(NAME) : $(OBJ) $(HEADER)
	make -C libft
	$(CC) $(FLAGS) $(NAME) $(OBJ) -o $(EXEC)
	$(CC) $(FLAGS) $(NAME) visu/main_ncurses.c -lncurses -o see

clean :
	make -C libft clean
	@rm -rf $(OBJ)

fclean :	clean
	make -C libft fclean
	@rm -rf $(NAME)
	rm -rf $(EXEC)

re : fclean all
