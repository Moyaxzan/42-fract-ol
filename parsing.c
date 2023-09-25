/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:57:45 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/25 18:48:40 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_set(char *str, t_window *window)
{
	if (ft_strncmp(str, "bonus", 6) || ft_strncmp(str, "b", 2))
		window->set = BONUS_F;
	else if (ft_strncmp(str, "julia", 6) || ft_strncmp(str, "j", 2))
		window->set = JULIA;
	else if (ft_strncmp(str, "mandelbrot", 6) || ft_strncmp(str, "m", 2))
		window->set = MANDELBROT;
	return ;
}

//TODO : improve this ? 
void	get_julia(char *real, char *im, t_window *window)
{
	window->julia_cmplx = malloc(sizeof(t_point));
	window->julia_cmplx->x = ft_atoi(real);
	window->julia_cmplx->y = ft_atoi(im);
}

int	parse(int argc, char **argv, t_window *window)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (-1); //TODO help message
	get_set(argv[i++], window);
	if (!window->set || (window->set != JULIA && argc > 3)
		|| (window->set == JULIA && argc > 5))
		return (write(2, "error\n", 6));	//TODO: better help mssg
	if (window->set == JULIA)
	{
		get_julia(argv[i], argv[i + 1], window);
		i = 4;
	}
	// TODO : get color
	return (0);
}
