/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfind_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:32:40 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/17 13:55:27 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

/*
**	A generic search function, a search key that is represented by an incomplete
** type pointer. Restores the type to a fully passed pointer to the comparison
** function. The search is conducted until a match is found or the end of the
** list is reached. In the first case, the return value is a pointer to this
** node of the linked list, in the second, a pointer to zero.
*/

t_dlist			*ft_dlstfind_r(t_dlist *head, void *data_ref,
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
		if (!(result = (*cmp)(curr, data_ref)) || curr->prev == head)
			break ;
		curr = curr->prev;
	}
	return (!result ? curr : NULL);
}
