/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:35:16 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/10 21:13:22 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

/*
** The address of the pointer to the first node in the linked list is passed
** to the function as the first argument, and the pointer to the newly created
** node of the linked list is passed by value as the second argument. It is
** required to make a new node first in the linked list, the parameter of which
** is transferred.
*/

void				ft_dlstadd(t_dlist **head, t_dlist *new)
{
	t_dlist			*last;

	if (head && new)
	{
		if (*head)
		{
			last = (*head)->prev;
			new->next = *head;
			new->prev = last;
			(*head)->prev = new;
			last->next = (*head)->prev;
			*head = new;
		}
		else
		{
			*head = new;
			new->next = new;
			new->prev = new;
		}
	}
	return ;
}
