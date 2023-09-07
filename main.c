/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:33 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/07 15:22:04 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;
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

int	handle_no_event(void *window)
{
	if (!window)
		return (1);
    return (0);
}

int	handle_input(int keysym, t_window *data)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return (0);
}

#include <stdio.h>
int	handle_keypress(int keysym, t_window *window)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(window->mlx_ptr, window->win_ptr);

    printf("Keypress: %d\n", keysym);
    return (0);
}

int	handle_keyrelease(int keysym, void *window)
{
	if (!window)
		return (1);
    printf("Keyrelease: %d\n", keysym);
    return (0);
}

int	main(void)
{
	t_window	*window;
	int			x;
	int			y;

	window = init_window();
	if (!window)
		return (MLX_ERROR);
	window->img.mlx_img = mlx_new_image(window->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &(window->img.bpp), &(window->img.line_len), &(window->img.endian));
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			if (y == x || x == WINDOW_WIDTH / 2 || y == WINDOW_HEIGHT / 2)
			{
				img_pix_put(&(window->img), x, y, 0x0FFFFFF);
			}
			y++;
		}
		x++;
	}
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
