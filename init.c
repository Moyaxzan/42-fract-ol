/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:19:03 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/04 15:29:37 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window	*init_window(void)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		return (0x0);
	window->win_ptr = 
		mlx_new_window(window->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fract'ol");
	if (!window->win_ptr)
	{
		free(window->mlx_ptr);
		return (0x0);
	}
	return (window);
}
