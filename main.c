/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:33 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/19 18:17:14 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colors_kirlian(int colors[12])
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

int	main(int argc, char **argv)
{
	t_window	*window;
	int			colors[12];

	if (parse(argc, argv) & 0b100)
		return (write(1, "Error : invalid arguments\n", 27));
	window = init_window();
	if (!window)
		return (MLX_ERROR);
	window->img.mlx_img = mlx_new_image(window->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!window->img.mlx_img)
		return (MLX_ERROR);
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &(window->img.bpp), &(window->img.line_len), &(window->img.endian));

	colors_kirlian(colors);
	draw_mdb(window, colors);

	if (hook_n_loop(window))
		return (MLX_ERROR);
	return (exit_mlx(window));
}
