/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:05:59 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/08 12:45:46 by taospa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*res;
	size_t			len_malloc;

	len_malloc = nmemb * size;
	if (len_malloc / size != nmemb)
		return (0x0);
	res = malloc(nmemb * size);
	if (!res)
		return (0x0);
	ft_memset(res, 0, nmemb * size);
	return ((void *) res);
}
