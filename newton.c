/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:30:07 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/26 19:58:17 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static float	is_in_newton(t_point c)
{
	t_point	z;
	float	i;
	t_point	attractor;

	attractor = (t_point){-0.25, -0.25};
	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (i < NB_ITER)
	{
		i = i + 1.0;
		t_point temp = ft_cosh(c);
		c = divide_cmplx(add_cmplx(mult_cmplx(c, ft_sinh(c)),
			(t_point){-temp.x + 1, -temp.y}), ft_sinh(c));
		if (modulus((t_point){c.x - attractor.x, c.y - attractor.y}) > 0.1)
			return (i);
	}
	return (i);
}

static int	get_color(int colors[12], float coefs[11], float iter)
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

int	draw_newton(t_window *window, int colors[12], float coefs[11], float zoom)
{
	int		x;
	int		y;
	double	p_y;
	double	p_x;
	float	i;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		p_y = (y - WIN_HEIGHT / 2.0) / (0.5 * zoom * WIN_HEIGHT) + START_Y;
		x = -1;
		while (++x < WIN_WIDTH)
		{
			p_x = 1.5 * (x - WIN_WIDTH / 2.0)
				/ (0.5 * zoom * WIN_WIDTH) + START_X;
			i = is_in_newton((t_point){p_x, p_y});
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
