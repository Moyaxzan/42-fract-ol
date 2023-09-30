/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:50:08 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/30 15:04:55 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_no_event(void *window)
{
	if (!window)
		return (1);
	return (0);
}

int	handle_input(int keysym, t_window *window)
{
	if (keysym == K_A_UP || keysym == K_W)
		ft_move(WIN_WIDTH / 2, WIN_HEIGHT / 4, window);
	else if (keysym == K_A_DOWN || keysym == K_S)
		ft_move(WIN_WIDTH / 2, 3 * WIN_HEIGHT / 4, window);
	else if (keysym == K_A_LEFT || keysym == K_A)
		ft_move(WIN_WIDTH / 4, WIN_HEIGHT / 2, window);
	else if (keysym == K_A_RIGHT || keysym == K_D)
		ft_move(3 * WIN_WIDTH / 4, WIN_HEIGHT / 2, window);
	else if (keysym == K_Q && window->color > 0x000050)
		window->color *= 0.9;
	else if (keysym == K_E && window->color < 0x0FFFFFFF)
		window->color *= 1.1;
	else if (keysym == K_PLUS)
		window->zoom *= 1.2;
	else if (keysym == K_MINUS)
		window->zoom *= 0.8;
	else if ((keysym == K_OPBRAC || keysym == K_CLBRAC)
		&& window->set == JULIA)
		change_julia(keysym, window);
	else if (keysym == XK_Escape)
		clean_exit(0, window);
	draw(window);
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
