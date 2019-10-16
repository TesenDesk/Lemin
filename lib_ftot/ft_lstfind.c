/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:37:20 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 20:11:58 by jjerde           ###   ########.fr       */
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

t_list	*ft_lstfind(t_list *head, void *data_ref,
		int (*cmp)(const void *min, const void *sub))
{
	int	result;

	if (!head || !data_ref || !cmp)
		return (NULL);
	result = 0;
	while (head)
	{
		if (!(result = (*cmp)(head, data_ref)))
			break ;
		head = head->next;
	}
	return (!result ? head : NULL);
}
