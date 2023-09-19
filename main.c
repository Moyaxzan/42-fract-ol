/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:33 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/18 16:41:45 by tsaint-p         ###   ########.fr       */
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
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	main(void)
{
	t_window	*window;

	window = init_window();
	if (!window)
		return (MLX_ERROR);
	window->img.mlx_img = mlx_new_image(window->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &(window->img.bpp), &(window->img.line_len), &(window->img.endian));

	draw_mdb(window, 0x0FFFFFF);

	/* Setup hooks */ 
	mlx_loop_hook(window->mlx_ptr, &handle_no_event, window);
	mlx_key_hook(window->win_ptr, &handle_input, window);
	mlx_hook(window->win_ptr, KeyPress, KeyPressMask, &handle_keypress, window);
	mlx_hook(window->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, window);

	mlx_loop(window->mlx_ptr);

	// exit and free
	mlx_destroy_image(window->mlx_ptr, window->img.mlx_img);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window);
}
