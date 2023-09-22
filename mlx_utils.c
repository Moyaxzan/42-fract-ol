/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:06:30 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/22 15:17:45 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	exit_mlx(t_window *window)
{
	if (!window)
		return (1);
	mlx_destroy_image(window->mlx_ptr, window->img.mlx_img);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window);
	return (0);
}

int	hook_n_loop(t_window *window)
{
	//mlx_loop_hook(window->mlx_ptr, &handle_no_event, window);
	mlx_key_hook(window->win_ptr, &handle_input, window);
	mlx_hook(window->win_ptr, ButtonPress, ButtonPressMask, &handle_scroll, window);
	mlx_loop(window->mlx_ptr);
	return (0);
}
