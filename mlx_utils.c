/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:06:30 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/26 12:25:19 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

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

int	hook_n_loop(t_window *window)
{
	mlx_key_hook(window->win_ptr, &handle_input, window);
	mlx_mouse_hook(window->win_ptr, mouse_events, window);
	//mlx_hook(window->win_ptr, DestroyNotify, StructureNotifyMask,
		//exit_mlx, window);
	mlx_loop(window->mlx_ptr);
	return (0);
}
