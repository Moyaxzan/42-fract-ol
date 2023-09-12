/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:33 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/12 17:47:30 by tsaint-p         ###   ########.fr       */
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

t_point	iterate(t_point c)
{
	int		i;
	t_point	z;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (i++ < NB_ITER)
		z = add_cmplx(mult_cmplx(z, z), c); // Zn+1 = Zn^2 + c
	return (z);
}

int	is_in_mandelbrot(t_point point)
{
	//double x0 = (double)point.x / WINDOW_WIDTH * 3.5 - 2.5; // Adjust the scaling and translation factors
	//double y0 = (double)point.y / WINDOW_HEIGHT * 2.0 - 1.0; // Adjust the scaling and translation factors

	if (modulus(iterate(point)) > 4)
		return (1);
	return (0); // The point is in the Mandelbrot set
}

int	draw(t_img *img, int base_color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			if (is_in_mandelbrot((t_point){x, y}))
			{
				img_pix_put(img, x, y, base_color);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	main(void)
{
	t_window	*window;

	window = init_window();
	if (!window)
		return (MLX_ERROR);
	window->img.mlx_img = mlx_new_image(window->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &(window->img.bpp), &(window->img.line_len), &(window->img.endian));

	draw(&(window->img), 0x0FFFFFF);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img.mlx_img, 0, 0);

	/* Setup hooks */ 
	mlx_loop_hook(window->mlx_ptr, &handle_no_event, window);
	mlx_key_hook(window->win_ptr, &handle_input, window);
	mlx_hook(window->win_ptr, KeyPress, KeyPressMask, &handle_keypress, window); /* ADDED */
	mlx_hook(window->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, window); /* CHANGED */

	mlx_loop(window->mlx_ptr);

	// exit and free
	mlx_destroy_image(window->mlx_ptr, window->img.mlx_img);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window);
}
