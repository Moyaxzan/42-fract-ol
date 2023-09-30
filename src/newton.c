/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:30:07 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/30 21:12:40 by tsaint-p         ###   ########.fr       */
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
	return (ft_max(fabs(c.x), fabs(c.y)) < 0.01);
}

static int	newton_raphson(t_point c)
{
	int	math_error;
	int	colors[3];
	int	i;

	i = 0;
	math_error = 0;
	colors[0] = 0x0FF0000;
	colors[1] = 0x000FF00;
	colors[2] = 0x0000000;
	while (i++ < NB_ITER)
	{
		c = f(c, &math_error);
		if (math_error)
			return (colors[2]);
		if (is_root(add_cmplx(attractor(c), (t_point){-c.x, -c.y})))
			break ;
	}
	//printf("c.y = %f, i = %d, all = %d\n", c.y, i, ((int)(round(c.y / M_PI / 2) + i) % 3));
	//fflush(stdout);
	return (colors[abs((int)(round(c.y / M_PI / 2) + i) % 3)]);
}

//TODO: add offset
int	draw_newton(t_window *window)
{
	int		x;
	int		y;
	t_point	p;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		p.y = (y - WIN_HEIGHT / 2.0)
			/ (0.5 * window->zoom * WIN_HEIGHT) + START_Y;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			p.x = 1.5 * (x - WIN_WIDTH / 2.0)
				/ (0.5 * window->zoom * WIN_WIDTH) + START_X;
			img_pix_put(&window->img, x, y, newton_raphson(p));
		}
	}
	mlx_put_image_to_window
		(window->mlx_ptr, window->win_ptr, window->img.mlx_img, 0, 0);
	return (1);
}
