
SRCS = main.c\
		utils.c\
		ray_casting_utils.c\
		hooks1.c\
		hooks2.c\
		dda_algo.c\
		player_movements1.c\
		player_movements2.c\
		ray_casting.c\
		angle_utils.c\
		textures.c\
		mini_map.c\
		colors.c\
		wall_rendering.c\
		../parsing/check_components.c\
		../parsing/check_map_info.c\
		../parsing/check_map.c\
		../parsing/get_file_data.c\
		../parsing/parsing.c\
		../parsing/parsing_utils.c\
		../parsing/setup_map.c\
		../parsing/errors.c \
		../parsing/check_rgb_colors.c

OBJ =  $(SRCS:.c=.o)

B_SRCS = 

B_OBJ = $(B_SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ../libft/Inc

NAME = ../cub3d

LIBFT = ../libft/libft.a

all : $(NAME)

bonus : $(B_NAME)

%.o : %.c
	$(CC) $(CFLAGS)  -I/usr/include -I ../mlx_linux -c $< -o $@

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -L  ./minilibx-linux -lmlx_Linux  -L/usr/lib -I ../mlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(B_NAME) : $(B_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(B_NAME)

clean :
	rm -f $(OBJ)
	rm -f $(B_OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f $(B_NAME)

re : fclean all

.PHONY:  all clean fclean re





