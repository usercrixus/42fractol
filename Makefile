OBJS = \
	fractol_command.o \
	fractol_draw.o \
	fractol_fractal.o \
	fractol_main.o \
	fractol_interpolate.o \
	fractol_draw_utility.o \
	fractol_command_bonus.o \

MLX_PATH = /home/chaisneau/Documents/fractol/minilibx-linux
CFLAGS = -Wall -Wextra -Werror -I$(MLX_PATH)
LDFLAGS = -L$(MLX_PATH) -lX11 -lXext -lm -lmlx

all: fractol

fractol: $(OBJS)
	cc $(CFLAGS) $^ -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -o $@

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f fractol

re: fclean all

.PHONY: all clean fclean re
