/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:29:50 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/26 12:32:18 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MLX_ERROR 1
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define NB_ITER 200
# define DEGREE 2
# define START_X -0.5
# define START_Y 0.0
# define BONUS_F 3
# define JULIA 2
# define MANDELBROT 1
# define RAINBOW 6767
# define KIRLIAN 2021
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;	// bits per pixel
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

// TODO : don't forget to free julia_cmplx
typedef	struct s_window
{
	void	*mlx_ptr;
	t_img	img;
	void	*win_ptr;
	int		set;
	t_point	*julia_cmplx;
	int		color;

}	t_window;

/*----------------colors.c--------------------*/
void		colors_rainbow(int colors[12], float coefs[11]);
void		coefs_rainbow(float coefs[12]);
void		colors_kirlian(int colors[12], float coefs[11]);
void		coefs_kirlian(float coefs[12]);

/*----------------draw.c---------------------*/
int			draw(t_window *window);

/*----------------events.c-------------------*/
int			handle_input(int keysym, t_window *data);
int			mouse_events(int keysym, int x, int y, void *window);

/*-----------------exit.c---------------------*/
void		exit_mlx(t_window *window);
int			errnl(char *error_msg, int error_code);
int			clean_exit(int exit_code, t_window *window);

/*----------------init.c---------------------*/
int			init_mlx(t_window *window);
t_window	*init_window(void);

/*---------------mandelbrot.c----------------*/
int			draw_mdb(t_window *window, int *colors, float coefs[11], float zoom);

/*---------------math_utils.c----------------*/
t_point		mult_cmplx(t_point c1, t_point c2);
t_point		add_cmplx(t_point c1, t_point c2);
double		modulus(t_point z);
double		ft_atof(const char *str); //TODO : test it

/*---------------mlx_utils.c-----------------*/
void		img_pix_put(t_img *img, int x, int y, int color);
int			hook_n_loop(t_window *window);

/*-----------------parsing.c------------------*/
int			parse(int argc, char **argv, t_window *window);

/*------------------zoom.c-------------------*/
float		get_zoom(float add);

#endif
