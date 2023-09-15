/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:33 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/15 17:31:12 by tsaint-p         ###   ########.fr       */
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
	while (i++ < 10)
		z = add_cmplx(mult_cmplx(z, z), c); // Zn+1 = Zn^2 + c
	return (z);
}

#include <stdio.h>
int	is_in_mandelbrot(t_point c)
{
    t_point	z;
	int		i;

    z.x = 0.0;
    z.y = 0.0;
	i = 0;
	while (i++ < NB_ITER)
	{
		z = add_cmplx(mult_cmplx(z, z), c);
		if (modulus(z) > 4)
    		return (0); // The point is not in the Mandelbrot set   
	}
    return (1); // The point is likely in the Mandelbrot set
}

int	draw(t_window *window, int base_color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_WIDTH)
	{
    	double p_y = (y - WIN_HEIGHT / 2.0) / (0.5 * WIN_HEIGHT) + START_Y;
		x = 0;
		while (x < WIN_HEIGHT)
		{
    		double p_x = 1.5 * (x - WIN_WIDTH / 2.0) / (0.5 * WIN_WIDTH) + START_X;
			if (is_in_mandelbrot((t_point) {p_x, p_y}))
			{
				img_pix_put(&(window->img), x, y, base_color);
				printf("%d, %d -> in mandelbrot\n", x, y);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img.mlx_img, 0, 0);
	printf("image printed\n");
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

	draw(window, 0x0FFFFFF);

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
