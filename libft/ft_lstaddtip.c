/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:35:34 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 17:32:35 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	It finds the last node of the linked list, and returns pointer to it.
*/

void				ft_lstaddtip(t_list **head, t_list *new)
{
	t_list			*last;

	if (head && new)
	{
		last = *head;
		if (last)
		{
			last = ft_lstlast(last);
			last->next = new;
			new->next = NULL;
		}
		else
			*head = new;
	}
	return ;
}
