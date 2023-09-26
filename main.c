/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:33 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/26 12:46:51 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//TODO : free on errors !
int	main(int argc, char **argv)
{
	t_window	*window;

	window = init_window();
	if (argc < 2)
		return (clean_exit(errnl(
			"You must specify at least the fractal set", 1), window));
	parse(argc, argv, window);
	if (init_mlx(window))
		return (clean_exit(MLX_ERROR, window));
	draw(window);
	if (hook_n_loop(window))
		return (MLX_ERROR);
	return (0);
}
