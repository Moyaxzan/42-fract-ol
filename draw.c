/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:20:31 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/22 17:31:46 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//TODO : free on errors + change mdb check when julia added + make parsing in draw !
int	draw(t_window *window)
{
	int			colors[12];
	float		coefs[11];
	//static int	parsing;

	window->img.mlx_img = mlx_new_image(window->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!window->img.mlx_img)
		return (MLX_ERROR);
	window->img.addr = mlx_get_data_addr
		(window->img.mlx_img, &(window->img.bpp),
			&(window->img.line_len), &(window->img.endian));
	if (!window->img.addr)
		return (MLX_ERROR);
	if (window->parsing & 0b001)
		colors_kirlian(colors, coefs);
	else
		colors_rainbow(colors, coefs);
	if (!(window->parsing & 0b010))
		draw_mdb(window, colors, coefs, get_zoom(0));
	return (0);
}
