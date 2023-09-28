/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:30:07 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/28 21:34:38 by taospa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	rectangular_distance(t_point z1, t_point z2)
{
	double	dx;
	double	dy;

	dx = z1.x - z2.x;
	dy = z1.y - z2.y;
	return (fmax(fabs(dx), fabs(dy)));
}

int	color_indicator(t_point point)
{
	t_point	attractor_point;
	double	min_distance;
	double	distance;
	int		attractor;
	int		i;

	i = 0;
	while (i < NB_ITER)
	{
		attractor_point = (t_point){0, i * 2.0 * M_PI};
		distance = rectangular_distance(point, attractor_point);
		if (!i || rectangular_distance(point, attractor_point) < min_distance)
		{
			min_distance = distance;
			attractor = i;
		}
		i++;
	}
	return (attractor * (NB_ITER + 1) + (NB_ITER - attractor));
}

static float	is_in_newton(t_point c)
{
	float	i;
	t_point	temp;

	i = 0;
	while (i < NB_ITER)
	{
		temp = ft_cosh(c);
		c = divide_cmplx(mult_cmplx(c, add_cmplx(ft_sinh(c),
						(t_point){-temp.x + 1, -temp.y})), ft_sinh(c));
		i++;
		if (rectangular_distance(c, (t_point){0, i * 2.0 * M_PI}) < 0.01)
			break ;
	}
	return (color_indicator(c));
}

int	draw_newton(t_window *window)
{
	int		x;
	int		y;
	double	p_y;
	double	p_x;
	float	i;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		p_y = (y - WIN_HEIGHT / 2.0)
			/ (0.25 * window->zoom * 0.1 * WIN_HEIGHT) + START_Y;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			p_x = 1.5 * (x - WIN_WIDTH / 2.0)
				/ (0.25 * window->zoom * WIN_WIDTH) + START_X;
			i = is_in_newton((t_point){p_x, p_y});
			img_pix_put(&(window->img), x, y,
				(window->color * i) / window->zoom);
		}
	}
	mlx_put_image_to_window
		(window->mlx_ptr, window->win_ptr, window->img.mlx_img, 0, 0);
	return (1);
}
