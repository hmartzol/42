DIR = ./libft
LIB = $(DIR)/libft.a
NAME = ./fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MAIN = ./main.o
OBJ = $(addprefix $(DIR)/, ft_memset.o ft_bzero.o ft_memcpy.o\
ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o\
ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o\
ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o\
ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o\
ft_tolower.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o\
ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o\
ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o\
ft_putstr.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o\
ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o\
ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_puttab.o ft_puttab_fd.o ft_putlist.o\
ft_putlist_fd.o ft_lstend.o ft_readfile.o )
HDR = $(DIR)/libft.h

.PHONY: all
all: $(NAME)

.PHONY: lib
lib: $(LIB)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

$(NAME): $(MAIN) $(LIB)
	$(CC) $^ -o $@ $(CFLAGS)

%.o: %.c $(HDR)
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf $(MAIN)

.PHONY: cleanlib
cleanlib:
	rm -rf $(LIB)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: fcleanlib
fcleanlib: fclean cleanlib
	rm -rf $(OBJ)

.PHONY: relib
relib: fcleanlib lib

.PHONY: re
re: fclean all

.PHONY: run
run: all
	$(NAME)
