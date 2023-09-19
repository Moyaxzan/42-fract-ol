/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:29:33 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/19 19:09:25 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//TODO : free on errors !
int	main(int argc, char **argv)
{
	t_window	*window;
	int			parsing;

	parsing = parse(argc, argv);
	if (parsing & 0b100)
		return (write(1, "Error : invalid arguments\n", 27));
	window = init_window();
	if (!window)
		return (MLX_ERROR);
	draw(window, parsing);
	if (hook_n_loop(window))
		return (MLX_ERROR);
	return (exit_mlx(window));
}
