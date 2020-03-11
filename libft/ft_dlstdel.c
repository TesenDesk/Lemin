/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:46:01 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 19:13:39 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The first argument is a pointer to a node in the linked list, and the second
** argument is a pointer to a function for clearing the data contained in this
** node. It is required to free the memory by the pointer to the first node of
** the linked list with the help of the free() function and assign it a NULL
** value. You should also clear the node's data memory using the del() function.
** This should be done for this node and all subsequent ones in the linked list.
*/

void			ft_dlstdel(t_dlist **alst, void (*delptr)(void *, size_t))
{
	t_dlist		*next;
	t_dlist		*curr;

	if (alst && *alst)
	{
		if (!delptr)
			delptr = ft_delfunc_dummy;
		curr = *alst;
		while (TRUE)
		{
			next = curr->next;
			(*delptr)(curr->content, curr->content_size);
			free(curr);
			if (next == *alst)
				break ;
			curr = next;
		}
		*alst = NULL;
	}
	return ;
}
