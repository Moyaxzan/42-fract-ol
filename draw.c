/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:20:31 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/28 21:09:11 by taospa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

//TODO : free on errors + change mdb check when julia added
int	draw(t_window *window)
{
	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	if (window->set == MANDELBROT)
		draw_mdb(window);
	else if (window->set == JULIA)
		draw_julia(window);
	else if (window->set == NEWTON)
		draw_newton(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->img.mlx_img, 0, 0);
	return (0);
}
