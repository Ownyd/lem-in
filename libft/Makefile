# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlux <tlux@42.fr>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 06:20:44 by tlux              #+#    #+#              #
#    Updated: 2018/02/07 16:38:58 by tlux             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

NAME = libft.a
HEADER = libft.h
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
	  ft_lstdelone.c ft_contdel.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	  ft_strsplit.c ft_strtrim.c ft_strsub.c ft_toupper.c ft_tolower.c \
	  ft_strstr.c ft_strnstr.c ft_strrchr.c ft_count_if.c ft_foreach.c \
	  ft_print_params.c ft_sqrt.c ft_swap.c get_next_line.c \
	  ft_atoll.c ft_strfreejoin.c ft_strfreesub.c ft_roomadd.c ft_roomnew.c \
	  ft_tubeadd.c ft_tubenew.c find_room.c find_room_by_name.c \
	  ft_pathnew.c ft_pathadd.c find_room_extrems.c ft_isstrdigit.c ft_atoll.c \
	  ft_pathdel.c ft_roomdel.c ft_tabfree.c

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	@rm -rf $(OBJ)

fclean :	clean
	@rm -rf $(NAME)

re : fclean all
