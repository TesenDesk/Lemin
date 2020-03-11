/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:35:16 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/30 14:58:02 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The address of the pointer to the first node in the linked list is passed
** to the function as the first argument, and the pointer to the newly created
** node of the linked list is passed by value as the second argument. It is
** required to make a input node first in the linked list, the parameter of
** which is transferred.
*/

void				ft_dlstadd(t_dlist **head, t_dlist *input)
{
	t_dlist			*last;

	if (head && input)
	{
		if (*head)
		{
			last = (*head)->prev;
			input->next = *head;
			input->prev = last;
			(*head)->prev = input;
			last->next = (*head)->prev;
			*head = input;
		}
		else
		{
			*head = input;
			input->next = input;
			input->prev = input;
		}
	}
	return ;
}
