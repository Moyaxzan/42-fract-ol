/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:20:31 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/19 19:17:06 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	colors_kirlian(int colors[12])
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

static void	colors_rainbow(int colors[12])
{
	colors[0] = 0x0ff0000;
	colors[1] = 0x0ff8000;
	colors[2] = 0x0ffff00;
	colors[4] = 0x080ff00;
	colors[5] = 0x000ff80;
	colors[6] = 0x000ffff;
	colors[7] = 0x00080ff;
	colors[8] = 0x00000ff;
	colors[9] = 0x08000ff;
	colors[10] = 0x0ff00ff;
	colors[11] = 0x0ff0080;
}

//TODO : free on errors + change mdb check when julia added
int	draw(t_window *window, int parsing)
{
	int			colors[12];

	window->img.mlx_img = mlx_new_image(window->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!window->img.mlx_img)
		return (MLX_ERROR);
	window->img.addr = mlx_get_data_addr
		(window->img.mlx_img, &(window->img.bpp),
			&(window->img.line_len), &(window->img.endian));
	if (!window->img.addr)
		return (MLX_ERROR);
	if (parsing & 0b001)
		colors_kirlian(colors);
	else
		colors_rainbow(colors);
	if (!(parsing & 0b010))
		draw_mdb(window, colors);
	return (0);
}
