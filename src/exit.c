/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:14:54 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/10/02 12:46:01 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	exit_mlx(t_window *window)
{
	if (!window)
		return ;
	if (!window->mlx_ptr)
		return (free(window));
	mlx_destroy_image(window->mlx_ptr, window->img.mlx_img);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window);
	window = NULL;
}

void	print_fractal_options(void)
{
	ft_putendl_fd("+===============  Execution  ===============+", 1);
	ft_putendl_fd("Which fractal would you like to view?", 1);
	ft_putendl_fd("\tm - mandelbrot", 1);
	ft_putendl_fd("\tj - julia", 1);
	ft_putendl_fd("\tn - newton", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol <set>  <color>", 1);
	ft_putendl_fd("\t\t./fractol newton 0x0454545\e[0m", 1);
	ft_putendl_fd("\nFor Julia, you may specify starting values", 1);
	ft_putendl_fd("for the initial fractal shape.", 1);
	ft_putendl_fd("Values must be between -2.0 and 2.0.", 1);
	ft_putstr_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol julia <real> <imag>", 1);
	ft_putendl_fd("\t\t./fractol julia -1.476  0.00\e[0m", 1);
	ft_putendl_fd("\n+================  Controls  ================+", 1);
	ft_putendl_fd("You can use your keyboaard :\n\t<W> <A> <S> <D> to move.", 1);
	ft_putendl_fd("\t<Q> <E> to change the color", 1);
	ft_putendl_fd("\t<[> <]> to change julia parameters", 1);
	ft_putendl_fd("\t<=> <-> to ZOOM in or out", 1);
	ft_putendl_fd("\nYou can also use your mouse :", 1);
	ft_putendl_fd("\tright/left click to zoom in/out on cursor", 1);
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
