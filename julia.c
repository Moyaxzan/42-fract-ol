/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:20:40 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/29 14:43:08 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static float	is_in_julia(t_point c, t_point *start)
{
	t_point	z;
	float	i;

	z.x = start->x;
	z.y = start->y;
	i = 0;
	while (i < NB_ITER)
	{
		i = i + 1.0;
		c = add_cmplx(mult_cmplx(c, c), z);
		if (modulus(c) > 4)
			return (i);
	}
	return (i);
}

int	draw_julia(t_window *win)
{
	int		x;
	int		y;
	float	i;
	t_point	p;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		p.y = (y - WIN_HEIGHT / 2.0) /
			(0.5 * win->zoom * WIN_HEIGHT) + START_Y + win->offset.y;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			p.x = 1.5 * (x - WIN_WIDTH / 2.0)
				/ (0.5 * win->zoom * WIN_WIDTH) + START_X + win->offset.x;
			i = is_in_julia((t_point){p.x, p.y}, win->julia_cmplx);
			if (i == NB_ITER)
				img_pix_put(&(win->img), x, y, 0x0000000);
			else
				img_pix_put(&(win->img), x, y, (win->color * i) / win->zoom);
		}
	}
	mlx_put_image_to_window
		(win->mlx_ptr, win->win_ptr, win->img.mlx_img, 0, 0);
	return (1);
}
