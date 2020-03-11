/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:38:25 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/20 18:27:47 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstforeach_if(t_list *node, void (*fptr)(void *),
		void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*curr;

	curr = node;
	if (!node || !fptr || !data_ref || !cmp)
		return ;
	while (curr)
	{
		if (!(*cmp)(curr->content, data_ref))
			(*fptr)(curr->content);
		curr = curr->next;
	}
	return ;
}
