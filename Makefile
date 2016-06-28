NAME = ls

SRC_PATH = ./sources

SRC_NAME = ft_rights_str.c ft_read_ls_opt.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I./includes -I./libft/includes

all: $(NAME)

$(LIB):
	make printf -C ./libft

$(NAME):  $(LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIB)

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C ./libft
	rm -fv $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -fv $(NAME) $(LIB)

re: fclean all

.PHONY: all, clean, fclean, re, test

norme:
	norminette $(SRC) includes/push_swap.h

test: $(LIB) $(OBJ)
	rm -fv test
	$(CC) -o stat.o -c stat.c $(CPPFLAGS)
	$(CC) -o test $(OBJ) stat.o $(CPPFLAGS) $(LIB)
