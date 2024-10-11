NAME = cub3D

SRC = main.c parsing/check_components.c parsing/check_map_info.c \
		parsing/check_map.c parsing/get_file_data.c parsing/parsing.c \
		parsing/utils.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
#-fsanitize=address

FLAG = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

LIBFT_A = libft/libft.a

all : $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRC) $(FLAG) $(LIBFT_A) -o $(NAME)

clean:
	cd libft && rm -rf *.o
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	cd libft && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re