/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddtip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:26:13 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/30 14:56:40 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	It finds the last node of the linked list, and returns pointer to it.
*/

void				ft_dlstaddtip(t_dlist **head, t_dlist *input)
{
	t_dlist			*last;

	if (head && input)
	{
		if (*head)
		{
			last = (*head)->prev;
			input->prev = last;
			input->next = *head;
			(*head)->prev = input;
			last->next = (*head)->prev;
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
