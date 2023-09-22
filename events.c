/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:50:08 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/22 17:39:14 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_no_event(void *window)
{
	if (!window)
		return (1);
	return (0);
}

//TODO: exit better than this
int	handle_input(int keysym, t_window *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	handle_scroll(int keysym, t_window *window)
{
	if (keysym == Button4)
	{
		get_zoom(0.1);
		draw(window);
	}
	else if (keysym == Button5)
	{
		get_zoom(-0.1);
		draw(window);
	}
	return (0);
}
