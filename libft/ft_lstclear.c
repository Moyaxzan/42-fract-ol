/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:21:00 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/05/02 16:57:02 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_cell;

	if (!del || !lst)
		return ;
	current_cell = *lst;
	while (current_cell)
	{
		*lst = current_cell->next;
		del(current_cell->content);
		free(current_cell);
		current_cell = *lst;
	}
}
