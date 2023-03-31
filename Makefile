GCC = gcc -Wall -Wextra -Werror
HEAD = -I .so_long.h
HEAD = -I .so_long_bonus/so_long_bonus.h
MAKE = make
SRCS = so_long.c check_argv.c ft_verif_map.c \
		ft_verif_elem.c ft_go_to_exit.c \
		ft_keyboard.c ft_show_map.c ft_images_utils.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRCS_B = ./so_long_bonus/so_long_bonus.c ./so_long_bonus/check_argv.c ./so_long_bonus/ft_verif_map.c \
		./so_long_bonus/ft_verif_elem.c ./so_long_bonus/ft_go_to_exit.c ./so_long_bonus/ft_enemy.c \
		./so_long_bonus/ft_keyboard.c ./so_long_bonus/ft_show_map.c ./so_long_bonus/ft_images_utils.c \
		./so_long_bonus/get_next_line/get_next_line.c ./so_long_bonus/get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}

NAME = so_long
NAME_B = so_longbonus

all : $(NAME)

$(NAME) :
	@${MAKE} -C ./libft
	@$(GCC) $(HEAD) ${SRCS} -g -L. -lmlx -framework AppKit -framework OpenGL -L ./libft -lft -o ${NAME}

clean :
	@rm -f $(OBJS)
	@$(MAKE) clean -C ./libft

fclean : clean
	@rm -f ${NAME}
	@$(MAKE) fclean -C ./libft

re : fclean all

bonus :
	@${MAKE} -C ./so_long_bonus/libft
	@$(GCC) $(HEAD_B) ${SRCS_B} -g -L. -lmlx -framework AppKit -framework OpenGL -L ./so_long_bonus/libft -lft -o ${NAME_B}

cleanbonus :
	@rm -f $(OBJS)
	@$(MAKE) clean -C ./so_long_bonus/libft

fcleanbonus :
	@rm -f ${NAME_B}
	@$(MAKE) fclean -C ./so_long_bonus/libft

rebonus : fcleanbonus bonus

.PHONY : all make clean fclean re cleanbonus fcleanbonus rebonus
