SRC		=	main.c hooks.c draw.c fractals.c color.c utils.c
PROG	=	fractol
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3
LIBDIR	=	./libft
LIB		=	$(LIBDIR)/libft.a
HEADER	=	fractol.h

.PHONY	:	all re clean fclean

all		:	$(PROG)

$(LIB)	:
			make -s -C $(LIBDIR)

$(PROG)	:	$(SRC) $(LIB) $(HEADER)
			$(CC) $(CFLAGS) $(SRC) -L $(LIBDIR) -lft -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(PROG)

clean	:
			make clean -C $(LIBDIR)

fclean	:
			rm -f $(PROG)
			make fclean -C $(LIBDIR)

re		:	fclean all