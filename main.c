/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:33 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/19 12:52:23 by tsaint-p         ###   ########.fr       */
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

void	init_colors(int colors[12])
{
	colors[0] = 0x0FFFFFF;
	colors[1] = 0x0fdebff;
	colors[2] = 0x0dca2fb;
	colors[4] = 0x0ba75c9;
	colors[5] = 0x08c4dbe;
	colors[6] = 0x03C2FA8;
	colors[7] = 0x02D237E;
	colors[8] = 0x0261D69;
	colors[9] = 0x017123F;
	colors[10] = 0x00F0C2A;
	colors[11] = 0x0000000;
}

int	main(void)
{
	t_window	*window;
	int			colors[12];

	window = init_window();
	if (!window)
		return (MLX_ERROR);
	window->img.mlx_img = mlx_new_image(window->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &(window->img.bpp), &(window->img.line_len), &(window->img.endian));

	init_colors(colors);
	draw_mdb(window, colors);

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
