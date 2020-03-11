/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstforeach_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:22:19 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/21 12:45:06 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstforeach_if(t_dlist *node, void (*fptr)(void *),
					void *data_ref, int (*cmp)(void *, void *))
{
	t_dlist		*curr;

	curr = node;
	if (!node || !fptr || !data_ref ^ !cmp)
		return ;
	if (!cmp && !data_ref)
		ft_dlstforeach(node, fptr);
	while (TRUE)
	{
		if (!(*cmp)(curr->content, data_ref))
			(*fptr)(curr->content);
		if ((curr = curr->next) == node)
			break ;
	}
	return ;
}
