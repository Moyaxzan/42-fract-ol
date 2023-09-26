/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:50:08 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/26 12:48:28 by tsaint-p         ###   ########.fr       */
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
int	handle_input(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		clean_exit(0, window);
	return (0);
}

int	mouse_events(int keysym, int x, int y, void *window)
{
	if (!x && !y)
		return (0);
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
