/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:56:21 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/28 11:35:40 by taospa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

static size_t	size_num(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *str && ft_isdigit(*str))
	{
		str++;
		i++;
	}
	return (i);
}

double	ft_atof(const char *str)
{
	double	int_part;
	double	dec_part;
	size_t	len;
	int		sign;

	sign = 1;
	int_part = (double) ft_atoi(str);
	if (str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (str && ft_isdigit(*str) && *str != '.' && *str)
		str++;
	if (*str == '.')
		str++;
	dec_part = (double) ft_atoi(str);
	len = size_num(str);
	while (len--)
		dec_part /= 10;
	if (sign == 1)
		return (int_part + dec_part);
	return (int_part - dec_part);
}

t_point	divide_cmplx(t_point num, t_point deno)
{
	t_point	res;

	res.x = ((num.x * deno.x) + (num.y * deno.y))
		/ (pow(deno.x, 2) + pow(deno.y, 2));
	res.y = ((num.y * deno.x) + (num.x * deno.y))
		/ (pow(deno.x, 2) - pow(deno.y, 2));
	return (res);
}
