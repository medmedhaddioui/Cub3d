
SRCS = srcs

NAME = cub3d

LIBFT = libft

all :
	make -C $(LIBFT)
	make -C $(SRCS)

bonus : 
	make -C $(LIBFT)
	make bonus -C $(SRCS)

clean :
	make clean -C $(LIBFT)
	make clean -C $(SRCS)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY:  all clean fclean re