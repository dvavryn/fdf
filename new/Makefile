NAME	:= fdf

CC		:= cc

# CFLAGS	:= -Wall -Wextra -Werror

SRCS	:=	\
		main.c \
		map.c \

OBJS	:= $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -L./libft -lft -L/usr/lib -lmlx -lXext -lX11 -lm -lz -o $(NAME)
	# @make -C libft

all		: $(NAME)

%.o		: %.c
	@$(CC) -c $< -o $@

clean	:
	@rm -f $(OBJS)
	# @make clean -C libft

fclean	: clean
	@rm -f $(NAME)
	# @make fclean -C libft

re		: fclean all

.PHONY: all clean fclean re