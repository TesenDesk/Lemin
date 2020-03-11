/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:40:46 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/18 13:49:39 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate heap memory for a node from a linked list, and also allocate for
** its data an amount equal to the second argument. Copy the first argument to
** the space allocated for it. The element of the created node pointing to the
** next node must be NULL. Return a pointer to the newly created node. If the
** memory allocation step fails, return NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)ft_memalloc(1 * sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!((new->content) = ((void *)ft_memalloc(content_size))))
			return (NULL);
		new->content_size = content_size;
		ft_memcpy(new->content, content, new->content_size);
	}
	new->next = NULL;
	return (new);
}
