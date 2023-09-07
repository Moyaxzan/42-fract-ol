/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:33 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/04 17:13:31 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	degrade_vertical(void)
{
	static unsigned char	r;
	static unsigned char	g;
	static unsigned char	b;
	static int	indicator = 1;

	if (indicator == 1)
	{
		if (g == 0xff)
			indicator = 2;
		else
			g++;
	}
	if (indicator == 2)
	{
		if (!r)
			indicator = 3;
		else
			r--;
	}
	if (indicator == 3)
	{
		if (b == 0xff)
			indicator = 4;
		else
			b++;
	}
	if (indicator == 4)
	{
		if (!g)
			indicator = 5;
		else
			g--;
	}
	if (indicator == 5)
	{
		if (r == 0xff)
			indicator = 6;
		else
			r++;
	}
	if (indicator == 6)
	{
		if (!b)
			indicator = 1;
		else
			b--;
	}
	return (r * 65536 + g * 256 + b);
}

int	main(void)
{
	t_window	*window;
	int			i;
	int			j;
	int			color;

	window = init_window();
	i = 0;
	j = 0;
	color = 0xff0000;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		color = degrade_vertical();
		while (j < WINDOW_HEIGHT)
		{
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, i, j, color);
			j++;
		}
		i++;
	}
	mlx_loop(window->mlx_ptr);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
    mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
}
