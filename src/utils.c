/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:56:21 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/10/02 08:18:03 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
	float	denominator;

	denominator = (deno.x * deno.x) + (deno.y * deno.y);
	res.x = ((num.x * deno.x) + (num.y * deno.y)) / denominator;
	res.y = ((num.y * deno.x) - (num.x * deno.y)) / denominator;
	return (res);
}

static int	xchartoi(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

int	xtoi(const char *hexString)
{
	int	res;
	int	char_val;

	res = 0;
	if (hexString[0] == '0' && (hexString[1] == 'x'
			|| hexString[1] == 'X'))
		hexString += 2;
	while (*hexString != '\0')
	{
		char_val = xchartoi(*hexString);
		if (char_val == -1)
			return (-1);
		res = res * 16 + char_val;
		hexString++;
	}
	return (res);
}
