/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:14:54 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/26 13:07:01 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	ft_putendl_fd("\tm - Mandelbrot", 1);
	ft_putendl_fd("\tj - Julia", 1);
	ft_putendl_fd("\tb - Bonus", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol <type>\n\t\t./fractol M\e[0m", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	ft_putendl_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol J\n./fractol J 0.285 0.01\e[0m", 1);
}
int	errnl(char *error_msg, int error_code)
{
	ft_putendl_fd(error_msg, 2);
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