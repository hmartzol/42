# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 22:39:21 by hmartzol          #+#    #+#              #
#    Updated: 2016/01/31 03:08:12 by hmartzol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

SRC = main.c ft_menu.c ft_menu_main.c ft_init_term.c ft_free_menu.c ft_ptnew.c\
	  print_grid.c ft_size_window.c
OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc

INCLUDE = -I./libft/libft.h
LIBS = -lncurses -L libft/ -lft
FLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) libft
	@echo Compiling $(NAME)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ) -o $(NAME) $(LIBS)

.PHONY: libft
libft:
	@echo Compiling/linking libft.a
	make -C libft/

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all
