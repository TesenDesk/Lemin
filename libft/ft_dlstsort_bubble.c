/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsort_bubble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:10:29 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/01 18:09:13 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			swap(t_dlist *curr, t_dlist *ptr2, int *swapped)
{
	t_dlist			temp;

	temp.content = curr->content;
	temp.flow = curr->flow;
	curr->content = ptr2->content;
	curr->flow = ptr2->flow;
	ptr2->content = temp.content;
	ptr2->flow = temp.flow;
	*swapped = TRUE;
	return ;
}

void				ft_dlstsort_bubble(t_dlist *head)
{
	int				swapped;
	t_dlist			*curr;

	if (head == NULL || head->next == head)
		return ;
	curr = head;
	swapped = FALSE;
	while (TRUE)
	{
		swapped = FALSE;
		while (TRUE)
		{
			if (curr->next != head && curr->flow > curr->next->flow)
				swap(curr, curr->next, &swapped);
			if ((curr = curr->next) == head)
				break ;
		}
		curr = head;
		if (!swapped)
			break ;
	}
	return ;
}
