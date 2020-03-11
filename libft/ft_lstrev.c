/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:41:42 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:41:44 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function changes the order of access to the nodes of the linked list to
** the opposite one, and replaces the pointer to the first node from the
** previous first to the new first, which was previously the last.
** If there are fewer than two nodes in the list, nothing happens. Otherwise,
** first go preparation before running a cyclic transformation. Variables prev
** (previous), curr (current). Then the cyclic conversion itself: assigning
** curr-> next the value of the address of the previous node (prev) and then
** shifting the auxiliary pointers 1 forward. The loop terminates as soon as
** the pointer to the next item points to NULL. The function now replaces
** *head with a pointer to a new beginning.
*/

void	ft_lstrev(t_list **head)
{
	t_list	*prev;
	t_list	*curr;

	if (!head || !*head || !(*head)->next)
		return ;
	prev = NULL;
	curr = *head;
	*head = curr->next;
	while (*head)
	{
		curr->next = prev;
		prev = curr;
		curr = *head;
		*head = curr->next;
	}
	*head = curr;
}
