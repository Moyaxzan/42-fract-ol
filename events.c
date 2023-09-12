/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:50:08 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/12 17:38:47 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>

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
