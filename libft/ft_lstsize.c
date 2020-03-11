/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:42:00 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/27 22:51:02 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *head)
{
	size_t	size;

	size = 0;
	if (head)
		while (head)
		{
			head = head->next;
			++size;
		}
	return (size);
}
