# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 23:15:42 by hmartzol          #+#    #+#              #
#    Updated: 2016/02/08 20:49:01 by hmartzol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit

SRCDIR =	src
OBJDIR =	OBJ
INCDIR =	includes

MAIN =		main
ITEMS =		

OBJ =		$(patsubst %, $(OBJDIR)/%.o, $(ITEMS))

CC =		gcc
FLAGS =		-Wall -Wextra -Werror

INCLUDE =	-I $(INCDIR)/ -I libft/includes/
LIBS =		-L libft/ -lft

.PHONY: all
all: $(NAME)

$(NAME): libft/libft.a auteur $(OBJDIR) $(OBJ)
	$(CC) $(FLAGS) $(INCLUDE) $(LIBS) src/$(MAIN).c libft/libft.a -o $@

libft/libft.a:
	make re -C libft/

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(FLAGS) $(INCLUDE) $(LIBS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	clear
	norminette $(patsubst %, $(SRCDIR)/%.c, $(ITEMS)) $(INCDIR)/libft.h

auteur:
	echo "hmartzol\n" > auteur
