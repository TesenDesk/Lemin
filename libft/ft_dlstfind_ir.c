/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfind_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:32:40 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/28 15:41:43 by ftothmur         ###   ########.fr       */
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

int				ft_dlstfind_ir(t_dlist *head, void *data_ref,
					int (*cmp)(const void *min, const void *sub))
{
	t_dlist		*curr;
	int			result;
	int			index;

	if (!head || !data_ref || !cmp)
		return (FAILURE);
	curr = head->prev;
	result = 0;
	index = 0;
	while (TRUE)
	{
		if (!(result = (*cmp)(curr, data_ref)) || curr == head)
			break ;
		curr = curr->prev;
		++index;
	}
	return (!result ? index : FAILURE);
}
