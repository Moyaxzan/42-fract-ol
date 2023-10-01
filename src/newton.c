/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:30:07 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/10/01 18:15:12 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static t_point	f(t_point z, int *math_error)
{
	t_point	res;
	t_point	cosh;

	res = ft_sinh(z);
	if (res.x != res.y)
	{
		cosh = ft_cosh(z);
		res = divide_cmplx((t_point){cosh.x - 1, cosh.y}, res);
		res = add_cmplx(z, (t_point){-res.x, -res.y});
	}
	else
		*math_error = 1;
	return (res);
}

static t_point	attractor(t_point c)
{
	c.x = 0.0;
	c.y = roundf(c.y / M_PI / 2) * M_PI * 2;
	return (c);
}

static int	is_root(t_point c)
{
	float	abs_x;
	float	abs_y;

	abs_x = fabs(c.x);
	abs_y = fabs(c.y);
	if (abs_x > abs_y)
		return (abs_x < 0.01);
	return (fabs(c.y) < 0.01);
}

static int	newton_raphson(t_point c, int color)
{
	int	math_error;
	int	colors[3];
	int	i;

	i = 0;
	math_error = 0;
	colors[0] = color / color;
	colors[1] = color;
	colors[2] = color / 3;
	while (i++ < NB_ITER)
	{
		c = f(c, &math_error);
		if (math_error)
			return (colors[2]);
		if (is_root(add_cmplx(attractor(c), (t_point){-c.x, -c.y})))
			break ;
	}
	return (colors[abs((int)(round(c.y / M_PI / 2) + i) % 3)]);
}

int	draw_newton(t_window *win)
{
	int		x;
	int		y;
	t_point	p;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		p.y = (y - WIN_HEIGHT / 2.0)
			/ (0.5 * win->zoom * WIN_HEIGHT) + 3.15 + START_Y + win->offset.y;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			p.x = 1.5 * (x - WIN_WIDTH / 2.0)
				/ (0.5 * win->zoom * WIN_WIDTH) + START_X + win->offset.x;
			img_pix_put(&win->img, x, y, newton_raphson(p, win->color));
		}
	}
	mlx_put_image_to_window
		(win->mlx_ptr, win->win_ptr, win->img.mlx_img, 0, 0);
	return (1);
}
