DIR = .
NAME = $(DIR)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
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
ft_putlist_fd.o ft_lstappend.o ft_readfile.o ft_alstnew.o ft_alstadd.o\
ft_alstdel.o ft_alstdelone.o ft_alstappend.o ft_alstitter.o ft_alstmap.o\
ft_alsttop.o ft_alstbottom.o ft_alstsearchid.o ft_alstincer.o )
HDR = $(DIR)/libft.h

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HDR)
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all
