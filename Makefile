NAME = cub3D

SRC = main.c parsing.c utils.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

LIBFT_A = libft/libft.a

all : $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_A) -o $(NAME)

clean:
	cd libft && rm -rf *.o
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	cd libft && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re