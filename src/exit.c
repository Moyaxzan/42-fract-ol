/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:14:54 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/10/01 18:39:23 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	exit_mlx(t_window *window)
{
	if (!window || !window->mlx_ptr)
		return ;
	mlx_destroy_image(window->mlx_ptr, window->img.mlx_img);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window);
}

void	print_fractal_options(void)
{
	ft_putendl_fd("+===============  Available Fractals  ===============+", 1);
	ft_putendl_fd("Which fractal would you like to view?", 1);
	ft_putendl_fd("\tm - mandelbrot", 1);
	ft_putendl_fd("\tj - julia", 1);
	ft_putendl_fd("\tn - newton", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol <set>  <color>", 1);
	ft_putendl_fd("\t\t./fractol newton 0x0454545\e[0m", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	ft_putstr_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol julia\n\t\t./fractol julia 0.285 0.01\e[0m", 1);
}

int	errnl(char *error_msg, int error_code)
{
	ft_putstr_fd(W_RED, 2);
	ft_putendl_fd(error_msg, 2);
	ft_putendl_fd(W_RESET, 2);
	print_fractal_options();
	return (error_code);
}

int	clean_exit(int exit_code, t_window *window)
{
	if (window && window->julia_cmplx)
		free(window->julia_cmplx);
	exit_mlx(window);
	exit(exit_code);
}
