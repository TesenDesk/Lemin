/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:28:32 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/27 22:01:10 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	A generic search function, a search key that is represented by an incomplete
** type pointer. Restores the type to a fully passed pointer to the comparison
** function. The search is conducted until a match is found or the end of the
** list is reached. In the first case, the return value is a pointer to this
** node of the linked list, in the second, a pointer to zero.
*/

t_dlist			*ft_dlstfind(t_dlist *head, void *data_ref,
					int (*cmp)(const void *min, const void *sub))
{
	t_dlist		*curr;
	int			result;

	if (!head || !data_ref || !cmp)
		return (NULL);
	curr = head;
	result = 0;
	while (TRUE)
	{
		if (!(result = (*cmp)(curr, data_ref)) || curr->next == head)
			break ;
		curr = curr->next;
	}
	return (!result ? curr : NULL);
}
