/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:15:32 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/30 15:05:39 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

int	draw_mdb(t_window *win)
{
	int		x;
	int		y;
	float	i;
	t_point	p;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		p.y = (y - WIN_HEIGHT / 2.0) / (0.5 * win->zoom * WIN_HEIGHT)
			+ START_Y + win->offset.y;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			p.x = 1.5 * (x - WIN_WIDTH / 2.0) / (0.5 * win->zoom
					* WIN_WIDTH) + START_X - 0.67 + win->offset.x;
			i = is_in_mandelbrot((t_point){p.x, p.y});
			if (i == NB_ITER)
				img_pix_put(&(win->img), x, y, 0x0000000);
			else
				img_pix_put(&(win->img), x, y, win->color * i);
		}
	}
	mlx_put_image_to_window
		(win->mlx_ptr, win->win_ptr, win->img.mlx_img, 0, 0);
	return (1);
}
