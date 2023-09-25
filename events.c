/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:50:08 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/25 11:53:26 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

int	handle_no_event(void *window)
{
	if (!window)
		return (1);
	return (0);
}

//TODO: exit better than this
int	handle_input(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		exit_mlx(window);
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
