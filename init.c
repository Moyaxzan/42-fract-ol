/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:19:03 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/25 17:15:06 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	*init_window(void)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		return (0x0);
	window->win_ptr
		= mlx_new_window(window->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fract'ol");
	if (!window->win_ptr)
	{
		free(window->mlx_ptr);
		return (0x0);
	}
	window->img.mlx_img = mlx_new_image(window->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!window->img.mlx_img)
		return (0x0);
	window->img.addr = mlx_get_data_addr
		(window->img.mlx_img, &(window->img.bpp),
			&(window->img.line_len), &(window->img.endian));
	if (!window->img.addr)
		return (0x0);
	return (window);
}
