/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:20:31 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/29 14:27:09 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(int x, int y, t_window *window)
{
	if (!window)
		return ;
	window->offset.x += (((float)x / WIN_WIDTH) - 0.5) * 2 / window->zoom;
	window->offset.y += (((float)y / WIN_HEIGHT) - 0.5) * 2 / window->zoom;
	draw(window);
}

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
