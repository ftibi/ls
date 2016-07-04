NAME = ls

SRC_PATH = ./sources

SRC_NAME = ft_rights_str.c ft_read_ls_opt.c ft_file_fct.c ft_file_list.c\
			ft_file_info.c ft_print_file_info.c ft_error_ls.c \
			ft_upr_opt.c ft_print_all_files.c ft_is_dot_file.c

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

.PHONY: all, clean, fclean, re, test, stat

norme:
	norminette $(SRC) includes/push_swap.h

stat: $(LIB) $(OBJ)
	rm -fv stat
	$(CC) -o stat.o -c stat.c $(CPPFLAGS)
	$(CC) -o stat $(OBJ) stat.o $(CPPFLAGS) $(LIB)

test: $(LIB) $(OBJ) test.o test.c
	rm -fv test
	$(CC) -o test.o -c test.c $(CPPFLAGS)
	$(CC) -o test $(OBJ) test.o $(CPPFLAGS) $(LIB)
