/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstextract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:11:04 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/02 23:12:56 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist				*ft_dlstextract(t_dlist **head, t_dlist *node)
{
	t_dlist			*next;
	t_dlist			*prev;

	if (!head || !*head || !node)
		return (NULL);
	if ((*head)->next == *head)
	{
		if ((*head) != node)
			return (NULL);
		*head = NULL;
	}
	else
	{
		next = node->next;
		prev = node->prev;
		next->prev = prev;
		prev->next = next;
		if (*head == node)
			*head = next;
	}
	node->next = node;
	node->prev = node;
	return (node);
}
