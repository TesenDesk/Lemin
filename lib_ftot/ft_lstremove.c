/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:41:09 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 20:11:58 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

/*
**	For normal operation, we expect all three parameters to exist. This is the
** head and node of the linked list and a pointer to the comparison function.
**
**	The function frees the memory of the node of the linked list, changes the
** value of a pointer to it to a pointer to zero and, if necessary, changes the
** value to the head. It should distinguish three cases: the first - a coherent
** list is represented by a single element, then you need to delete the entire
** list; the second - the element to be deleted is at the beginning; and all
** other cases (one of the private instances of which is the node at the end of
** the list, but all of them are treated the same).
**
**	The return value is empty.
**
**	Link to related information.
** https://www.cs.bu.edu/teaching/c/linked-list/delete/
*/

void	ft_lstremove(t_list **head, t_list *node,
		int (*ft_lstcmp_next)(t_list *, void *))
{
	t_list	*finding;

	if (!head || !*head || !node)
		return ;
	if (*head == node)
	{
		*head = node->next;
		ft_memdel((void **)&node);
	}
	else
	{
		finding = ft_lstfind(*head, (void *)node, ft_lstcmp_next);
		finding->next = node->next;
		ft_memdel((void **)&node);
	}
	return ;
}
