SRCS = so_long.c check_argv.c ft_verif_map.c \
		ft_sl_split.c ft_verif_elem.c ft_go_to_exit.c \
		ft_keyboard.c ft_show_map.c ft_images_utils.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

GCC = gcc -Wall -Wextra -Werror

NAME = so_long

HEAD = -I .so_long.h

MAKE = make

all : $(NAME)

make :
	@${MAKE} -C ./libft

$(NAME) : make
	@$(GCC) $(HEAD) ${SRCS} -g -L. -lmlx -framework AppKit -framework OpenGL -L ./libft -lft -o ${NAME}

bonus :
	@${MAKE} -C ./so_long_bonus

clean :
	@rm -f $(OBJS)
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./so_long_bonus

fclean : clean
	@rm -f ${NAME}
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./so_long_bonus

re : fclean all

.PHONY : all make clean fclean re
