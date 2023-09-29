/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:50:08 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/29 14:27:13 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_no_event(void *window)
{
	if (!window)
		return (1);
	return (0);
}

int	handle_input(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		clean_exit(0, window);
	return (0);
}

int	handle_cross(t_window *window)
{
	clean_exit(0, window);
	return (0);
}

int	mouse_events(int keysym, int x, int y, void *window)
{
	if (keysym == Button1)
	{
		((t_window *)window)->zoom *= 1.2;
		ft_move(x, y, window);
	}
	else if (keysym == Button3)
	{
		if (((t_window *)window)->zoom > 0.0045)
			((t_window *)window)->zoom *= 0.8;
		ft_move(x, y, window);
	}
	return (0);
}
