/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstforeach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:01:14 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/24 13:39:28 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstforeach(t_dlist *node, void (*fptr)(void *))
{
	t_dlist	*curr;

	curr = node;
	if (fptr && node)
		while (TRUE)
		{
			(*fptr)(curr->content);
			if ((curr = curr->next) == node)
				break ;
		}
	return ;
}
