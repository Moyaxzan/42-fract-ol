/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:30:19 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/26 13:11:56 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	mult_cmplx(t_point c1, t_point c2)
{
	t_point	res;

	res.x = (c1.x * c2.x) - (c1.y * c2.y);
	res.y = (c1.x * c2.y) + (c1.y * c2.x);
	return (res);
}

t_point	add_cmplx(t_point c1, t_point c2)
{
	t_point	res;

	res.x = c1.x + c2.x;
	res.y = c1.y + c2.y;
	return (res);
}

double	modulus(t_point z)
{
	return ((sqrt((z.x * z.x) + (z.y * z.y))));
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

	int_part = (double) ft_atoi(str);
	while (str && ft_isdigit(*str) && *str != '.')
		str++;
	if (*str == '.')
		str++;
	dec_part = (double) ft_atoi(str);
	len = size_num(str);
	while (len--)
		dec_part /= 10;
	return (int_part + dec_part);
}
