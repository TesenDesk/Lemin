/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:38:53 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/13 18:47:41 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	It passes ptr to head, or any node, and follows to the and of rhe linked
** list. It returns ptr to the last node of the linked list.
*/

t_list	*ft_lstlast(t_list *head)
{
	t_list *last;

	last = head;
	if (last)
		while (last->next)
			last = last->next;
	return (last);
}
