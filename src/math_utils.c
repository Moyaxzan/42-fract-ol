/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:30:19 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/30 17:51:15 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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

t_point	ft_cosh(t_point z)
{
	t_point	res;

	res.x = cosh(z.x) * cosh(z.y);
	res.y = sinh(z.x) * sinh(z.y);
	return (res);
}

t_point	ft_sinh(t_point z)
{
	t_point	res;

	res.x = sinh(z.x) * cosh(z.y);
	res.y = cosh(z.x) * sinh(z.y);
	return (res);
}
