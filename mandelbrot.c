/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:15:32 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/18 16:41:57 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_point	iterate(t_point c)
{
	int		i;
	t_point	z;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (i++ < 10)
		z = add_cmplx(mult_cmplx(z, z), c); // Zn+1 = Zn^2 + c
	return (z);
}

static int	is_in_mandelbrot(t_point c)
{
    t_point	z;
	int		i;

    z.x = 0.0;
    z.y = 0.0;
	i = 0;
	while (i++ < NB_ITER)
	{
		z = add_cmplx(mult_cmplx(z, z), c);
		if (modulus(z) > 4)
    		return (0); // The point is not in the Mandelbrot set   
	}
    return (1); // The point is likely in the Mandelbrot set
}

int	draw_mdb(t_window *window, int base_color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_WIDTH)
	{
    	double p_y = (y - WIN_HEIGHT / 2.0) / (0.5 * WIN_HEIGHT) + START_Y;
		x = 0;
		while (x < WIN_HEIGHT)
		{
    		double p_x = 1.5 * (x - WIN_WIDTH / 2.0) / (0.5 * WIN_WIDTH) + START_X;
			if (is_in_mandelbrot((t_point) {p_x, p_y}))
			{
				img_pix_put(&(window->img), x, y, base_color);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img.mlx_img, 0, 0);
	return (1);
}
