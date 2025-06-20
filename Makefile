NAME	:= fdf
CC		:= cc
# CFLAGS	:= -Wall -Wextra -Werror
SRCS	:=	main.c 
OBJS	:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L../libft/ -lft -L../mlx/ -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME) -g

%.o: %.c
	$(CC) -I/usr/include -Imlx -c $< -o $@ -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re