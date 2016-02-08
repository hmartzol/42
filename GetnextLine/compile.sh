# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/19 17:16:00 by hmartzol          #+#    #+#              #
#    Updated: 2016/02/08 20:34:34 by hmartzol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libf/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
