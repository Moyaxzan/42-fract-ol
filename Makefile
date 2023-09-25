NAME = fractol

SRCS = main.c init.c events.c math_utils.c mandelbrot.c parsing.c mlx_utils.c \
	   draw.c zoom.c colors.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RM_FLAGS = -f

#####	LIBFT  #####
LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

######	MLX   ######
MLX_FLAGS = -lX11 -lXext -lmlx

MLX_PATH = ./minilibx-linux

MLX = $(MLX_PATH)/libmlx.a

#####	RULES   #####
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -L$(MLX_PATH) $^ $(MLX_FLAGS) -lm -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

$(MLX):
	make -C $(MLX_PATH)

clean:
	make -C $(LIBFTDIR) clean
	make -C $(MLX_PATH) clean
	rm $(RM_FLAGS) $(OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm $(RM_FLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean
