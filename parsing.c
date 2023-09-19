/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:57:45 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/19 18:35:12 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// TODO : check for rainbow (split function)
static int	check_arg(int *changed, char *arg)
{
	if (!ft_strncmp(arg, "mandelbrot", 11))
	{
		write(1, "ooo", 3);
		if (*changed & 0b010)
			return (0b100);
		*changed = *changed | 0b010;
		return (0b000);
	}
	if (!ft_strncmp(arg, "julia", 6))
	{
		if (*changed & 0b010)
			return (0b100);
		*changed = *changed | 0b010;
		return (0b010);
	}
	if (!ft_strncmp(arg, "kirlian", 8))
	{
		if (*changed & 0b001)
			return (0b100);
		*changed = *changed | 0b001;
		return (0b001);
	}
	return (0b100);
}

// return value :
// 1st bit : 0 = ok / 1 = Error
// 2nd bit : 0 = mandelbrot / 1 = julia
// 3rd bit : 0 = basic / 1 = kirlian
int	parse(int argc, char **argv)
{
	int	ret_value;
	int	changed;
	int	i;

	i = 1;
	ret_value = 0b000;
	changed = 0b000;
	if (argc < 2)
		return (0b100);
	while (i < argc && !(ret_value & 0b100))
		ret_value = ret_value | check_arg(&changed, argv[i++]);
	//check if things didn't changed but should have
	return (ret_value);
}
