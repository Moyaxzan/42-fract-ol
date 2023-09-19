/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:15:32 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/19 13:38:47 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_in_mandelbrot(t_point c)
{
    t_point	z;
	int		i;

    z.x = 0.0;
    z.y = 0.0;
	i = 0;
	while (++i < NB_ITER)
	{
		z = add_cmplx(mult_cmplx(z, z), c);
		if (modulus(z) > 4)
    		return (i); // The point is not in the Mandelbrot set   
	}
    return (i); // The point is likely in the Mandelbrot set
}

int	get_color(int colors[12], int iter)
{
	if (iter > 9 * NB_ITER / 12)
		return (colors[0]);
	if (iter > 8 * NB_ITER / 12)
		return (colors[1]);
	if (iter > 4 * NB_ITER / 12)
		return (colors[2]);
	if (iter > 2.3 * NB_ITER / 12)
		return (colors[3]);
	if (iter > 1.5 * NB_ITER / 12)
		return (colors[4]);
	if (iter > 0.9 * NB_ITER / 12)
		return (colors[5]);
	if (iter > 0.8 * NB_ITER / 12)
		return (colors[6]);
	if (iter > 0.65 * NB_ITER / 12)
		return (colors[7]);
	if (iter > 0.2 * NB_ITER / 12)
		return (colors[8]);
	if (iter > 0.1 * NB_ITER / 12)
		return (colors[9]);
	if (iter > 0.065 * NB_ITER / 12)
		return (colors[10]);
	return (colors[11]);
}

int	draw_mdb(t_window *window, int colors[12])
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
    	double p_y = (y - WIN_HEIGHT / 2.0) / (0.5 * WIN_HEIGHT) + START_Y;
		x = 0;
		while (x < WIN_WIDTH)
		{
    		double p_x = 1.5 * (x - WIN_WIDTH / 2.0) / (0.5 * WIN_WIDTH) + START_X;
			int iter = is_in_mandelbrot((t_point) {p_x, p_y});
			if (iter == NB_ITER)
				img_pix_put(&(window->img), x, y, 0x0);
			else
				img_pix_put(&(window->img), x, y, get_color(colors, iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img.mlx_img, 0, 0);
	return (1);
}
