#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrisse <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 20:58:36 by abrisse           #+#    #+#              #
#    Updated: 2016/01/30 10:13:36 by malaine          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	game_2048

SRC =	main.c 

OBJ =	main.o

FLAGS =	-Wall -Wextra -Werror -lncurses libft/*.c

all: $(NAME)

$(NAME):
		make -C libft/ fclean && make -C libft/
		gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
		/bin/rm -f $(OBJ)
		make -C libft/ clean

fclean:	clean
		/bin/rm -f $(NAME)
		make -C libft/ fclean

re: fclean all

allclean: all clean

reclean: re clean