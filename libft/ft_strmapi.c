/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taospa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:23:29 by taospa            #+#    #+#             */
/*   Updated: 2023/05/04 15:47:28 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	test(unsigned int i, char c)
// {
	// if (i % 2 && c >= 'A' && c <= 'Z')
		// return (c + 32);
	// return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*res;

	len = ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0x0);
	i = 0;
	while (i < len)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

// #include <stdio.h>
// int	main(void)
// {
	// char	*res;

	// res = ft_strmapi("hoHOhoHOhoHO", test);
	// printf("res = %s", res);
	// free(res);
	// return (1);
// }
