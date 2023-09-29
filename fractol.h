/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:29:50 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/29 11:58:05 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MLX_ERROR 1
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define NB_ITER 50
# define DEGREE 2
# define START_X 0.0
# define START_Y 0.0
# define NEWTON 3
# define JULIA 2
# define MANDELBROT 1
# define COL_DEFAULT 0x8c00ff
# define KIRLIAN 2021
# define W_RED "\e[1;31m" 
# define W_BLUE "\e[0;36m" 
# define W_RESET "\e[0;0m" 
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_window
{
	void	*mlx_ptr;
	t_img	img;
	void	*win_ptr;
	int		set;
	t_point	*julia_cmplx;
	int		color;
	float	zoom;

}	t_window;

/*----------------draw.c---------------------*/
int			draw(t_window *window);

/*----------------events.c-------------------*/
int			handle_input(int keysym, t_window *data);
int			mouse_events(int keysym, int x, int y, void *window);
int			handle_cross(t_window *window);

/*-----------------exit.c--------------------*/
void		exit_mlx(t_window *window);
int			errnl(char *error_msg, int error_code);
int			clean_exit(int exit_code, t_window *window);

/*----------------init.c---------------------*/
int			init_mlx(t_window *window);
t_window	*init_window(void);

/*----------------julia.c--------------------*/
int			draw_julia(t_window *window);

/*---------------mandelbrot.c----------------*/
int			draw_mdb(t_window *window);

/*---------------math_utils.c----------------*/
t_point		mult_cmplx(t_point c1, t_point c2);
t_point		add_cmplx(t_point c1, t_point c2);
double		modulus(t_point z);
t_point		ft_cos(t_point z);
t_point		ft_sin(t_point z);

/*---------------mlx_utils.c-----------------*/
void		img_pix_put(t_img *img, int x, int y, int color);
int			hook_n_loop(t_window *window);

/*----------------newton.c-------------------*/
int			draw_newton(t_window *window);

/*-----------------parsing.c-----------------*/
int			parse(int argc, char **argv, t_window *window);

/*-----------------utils.c-------------------*/
int			ft_issign(int c);
double		ft_atof(const char *str);
t_point		divide_cmplx(t_point num, t_point deno);

#endif
