NAME = fractol

SRC_DIR = src/

SRC = main.c init.c events.c math_utils.c mandelbrot.c parsing.c \
	   mlx_utils.c draw.c exit.c julia.c utils.c newton.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = obj/

OBJ = $(SRC:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

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

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

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
