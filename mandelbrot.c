/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:15:32 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/22 14:23:29 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static float	is_in_mandelbrot(t_point c)
{
	t_point	z;
	float	i;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (i < NB_ITER)
	{
		i = i + 1.0;
		z = add_cmplx(mult_cmplx(z, z), c);
		if (modulus(z) > 4)
			return (i);
	}
	return (i);
}

int	get_color(int colors[12], float coefs[11], float iter)
{
	if (iter > coefs[0] * NB_ITER / 12)
		return (colors[0]);
	if (iter > coefs[1] * NB_ITER / 12)
		return (colors[1]);
	if (iter > coefs[2] * NB_ITER / 12)
		return (colors[2]);
	if (iter > coefs[3] * NB_ITER / 12)
		return (colors[3]);
	if (iter > coefs[4] * NB_ITER / 12)
		return (colors[4]);
	if (iter > coefs[5] * NB_ITER / 12)
		return (colors[5]);
	if (iter > coefs[6] * NB_ITER / 12)
		return (colors[6]);
	if (iter > coefs[7] * NB_ITER / 12)
		return (colors[7]);
	if (iter > coefs[8] * NB_ITER / 12)
		return (colors[8]);
	if (iter > coefs[9] * NB_ITER / 12)
		return (colors[9]);
	if (iter > coefs[10] * NB_ITER / 12)
		return (colors[10]);
	return (colors[11]);
}

int	draw_mdb(t_window *window, int colors[12], float coefs[11])
{
	int		x;
	int		y;
	double	p_y;
	double	p_x;
	float	i;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		p_y = (y - WIN_HEIGHT / 2.0) / (0.5 * WIN_HEIGHT) + START_Y;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			p_x = 1.5 * (x - WIN_WIDTH / 2.0) / (0.5 * WIN_WIDTH) + START_X;
			i = is_in_mandelbrot((t_point){p_x, p_y});
			if (i == NB_ITER)
				img_pix_put(&(window->img), x, y, 0x0000000);
			else
				img_pix_put(&(window->img), x, y, get_color(colors, coefs, i));
		}
	}
	mlx_put_image_to_window
		(window->mlx_ptr, window->win_ptr, window->img.mlx_img, 0, 0);
	return (1);
}
