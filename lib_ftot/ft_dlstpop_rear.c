/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_rear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:07:33 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/10 21:18:59 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

t_dlist				*ft_dlstpop_rear(t_dlist **head)
{
	t_dlist			*pop;
	t_dlist			*last;
	t_dlist			*penultimate;

	pop = NULL;
	if (head && *head)
	{
		last = (*head)->prev;
		pop = last;
		if (last != *head)
		{
			penultimate = last->prev;
			penultimate->next = (*head);
			(*head)->prev = penultimate;
		}
		else
			*head = NULL;
	}
	return (pop);
}
