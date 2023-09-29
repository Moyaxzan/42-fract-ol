/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:30:07 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/28 23:59:44 by taospa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static float	iter_newton(t_point c)
{
	float	i;
	t_point	temp_sin;
	t_point	temp_cos;

	i = 0;
	while (i < NB_ITER)
	{
		temp_sin = ft_cos(c);
		temp_cos = ft_sin(c);
		if ((!temp_sin.x && !temp_sin.y) || !(temp_sin.x - temp_sin.y))
			break ;
		c = add_cmplx(c, divide_cmplx(temp_cos, temp_sin));
		i++;
	}
	return (i);
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
			i = iter_newton((t_point){p_x, p_y});
			img_pix_put(&(window->img), x, y,
				(window->color * i) / window->zoom);
		}
	}
	mlx_put_image_to_window
		(window->mlx_ptr, window->win_ptr, window->img.mlx_img, 0, 0);
	return (1);
}
