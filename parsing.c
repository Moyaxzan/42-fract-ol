/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:57:45 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/26 19:05:59 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_set(char *str, t_window *window)
{
	if (!ft_strncmp(str, "newton", 6) || !ft_strncmp(str, "n", 2))
		window->set = NEWTON;
	else if (!ft_strncmp(str, "julia", 6) || !ft_strncmp(str, "j", 2))
		window->set = JULIA;
	else if (!ft_strncmp(str, "mandelbrot", 11) || !ft_strncmp(str, "m", 2))
		window->set = MANDELBROT;
	return ;
}

//TODO : improve this ? 
int	get_julia(char *real, char *im, t_window *window)
{
	if ((real && !ft_isdigit(*real) && !ft_issign(*real))
		|| (im && !ft_isdigit(*im) && !ft_issign(*im)))
		return (-1);
	window->julia_cmplx->x = ft_atof(real);
	window->julia_cmplx->y = ft_atof(im);
	if (window->julia_cmplx->y == 0.00f && window->julia_cmplx->x == 0.00f)
		return (-1);
	return (0);
}

int	get_color(char *str, t_window *window)
{
	if (!ft_strncmp(str, "kirlian", 8))
		window->color = KIRLIAN;
	else if (!ft_strncmp(str, "rainbow", 8))
		window->color = RAINBOW;
	return (window->color);
}

void	parse_julia(t_window *window, int *i, int argc, char **argv)
{
	window->julia_cmplx = malloc(sizeof(t_point));
	if (!window->julia_cmplx)
		clean_exit(errnl("error on malloc", 666), window);
	if (argc < 4)
		*(window->julia_cmplx) = (t_point){0.2, 0.7667};
	else if (get_julia(argv[*i], argv[*i + 1], window) == -1)
		clean_exit(errnl("Wrong Julia arguments", 1), window);
	else
		*i = 4;
}

int	parse(int argc, char **argv, t_window *window)
{
	int	i;

	i = 1;
	get_set(argv[i++], window);
	if (!window->set || (window->set != JULIA && argc > 3)
		|| (window->set == JULIA && argc > 5))
		return (clean_exit(errnl("invalid arguments", 1), window));
	if (window->set == JULIA)
		parse_julia(window, &i, argc, argv);
	if (i < argc)
	{
		if (!get_color(argv[i], window))
			return (clean_exit(errnl("Wrong color set", 420), window));
	}
	else
		window->color = KIRLIAN;
	return (0);
}
