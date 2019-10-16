/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:41:06 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 20:11:58 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

t_dlist				*ft_dlstpop(t_dlist **head)
{
	t_dlist			*pop;
	t_dlist			*last;
	t_dlist			*second;

	pop = NULL;
	if (head && *head)
	{
		pop = *head;
		if ((last = (*head)->prev) != *head)
		{
			second = (*head)->next;
			last->next = second;
			second->prev = last;
			*head = second;
		}
		else
			*head = NULL;
	}
	return (pop);
}
