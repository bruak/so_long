NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
LIBFT			= ./libft/libft.a
LIBFT_1			= libft/
SRC =	*.c
MINILIBX := minilibx/
LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
RM = rm -f

all:
	make -C $(MINILIBX)
	make -C $(LIBFT_1)
	$(CC) $(CFLAGS) $(SRC) $(LIBRARY) $(LIBFT) -o $(NAME)

re: fclean all

clean:
	make -C $(MINILIBX) clean
	make -C $(LIBFT_1) clean
	$(RM) $(NAME)

fclean:
	make -C $(MINILIBX) clean
	make -C $(LIBFT_1) fclean
	$(RM) $(NAME)

.PHONY: all fclean clean re
