/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:20:31 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/26 12:55:00 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

//TODO : free on errors + change mdb check when julia added
int	draw(t_window *window)
{
	int			colors[12];
	float		coefs[11];

	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	if (window->color == KIRLIAN)
		colors_kirlian(colors, coefs);
	else if (window->color == RAINBOW)
		colors_rainbow(colors, coefs);
	if (window->set == MANDELBROT)
		draw_mdb(window, colors, coefs, get_zoom(0));
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->img.mlx_img, 0, 0);
	return (0);
}
