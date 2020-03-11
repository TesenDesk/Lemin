/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:46:54 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/27 22:54:12 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_dlstsize(t_dlist *head)
{
	int				size;
	t_dlist			*curr;

	size = 0;
	curr = head;
	if (head)
		while (TRUE)
		{
			curr = curr->next;
			++size;
			if (curr == head)
				break ;
		}
	return (size);
}
