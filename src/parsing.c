/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:57:45 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/10/01 19:04:12 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	get_set(char *str, t_window *window)
{
	if (!ft_strncmp(str, "--help", 7) || !ft_strncmp(str, "-h", 3))
		clean_exit(errnl(0x0, 0), window);
	if (!ft_strncmp(str, "newton", 7) || !ft_strncmp(str, "n", 2))
		window->set = NEWTON;
	else if (!ft_strncmp(str, "julia", 6) || !ft_strncmp(str, "j", 2))
		window->set = JULIA;
	else if (!ft_strncmp(str, "mandelbrot", 11) || !ft_strncmp(str, "m", 2))
		window->set = MANDELBROT;
	return ;
}

int	get_julia(char *real, char *im, t_window *window)
{
	if (!real || !im)
		return (-1);
	if ((!ft_isdigit(*real) && !(*real == '-' || *real == '+'))
		|| (!ft_isdigit(*im) && !(*im == '-' || *im == '+')))
		return (-1);
	window->julia_cmplx->x = ft_atof(real);
	window->julia_cmplx->y = ft_atof(im);
	if (window->julia_cmplx->y == 0.00f && window->julia_cmplx->x == 0.00f)
		return (-1);
	return (0);
}

static int	get_color(char *str, t_window *window)
{
	int	color;

	color = xtoi(str);
	if (color == -1)
		return (0);
	if (color < 16)
	{
		write(2, "hex value too low -> ", 21);
		return (0);
	}
	window->color = color;
	return (1);
}

void	parse_julia(t_window *window, int *i, int argc, char **argv)
{
	window->julia_cmplx = malloc(sizeof(t_point));
	if (!window->julia_cmplx)
		clean_exit(errnl("error on malloc", 666), window);
	if (argc < 4)
		*(window->julia_cmplx) = (t_point){-0.8, 0.156};
	else if (get_julia(argv[*i], argv[*i + 1], window) == -1)
		clean_exit(errnl("Wrong Julia arguments", 1), window);
	else if ((window->julia_cmplx->x < -2.0f || window->julia_cmplx->x > 2.0f)
			|| (window->julia_cmplx->y < -2.0f || window->julia_cmplx->y > 2.0f))
		clean_exit(errnl("Values of julia must be between -2.0 and 2.0"
			, 1), window);
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
			return (clean_exit(errnl("Wrong color hex", 420), window));
	}
	else
		window->color = COL_DEFAULT;
	return (0);
}
