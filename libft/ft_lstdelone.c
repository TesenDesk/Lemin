/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:37:08 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:37:09 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The first argument is a pointer to a node in the linked list, and the second
** argument is a pointer to a function for clearing the data contained in this
** node. It is required to free the memory by the pointer to the first node of
** the linked list with the help of the free() function and assign it a NULL
** value. You should also clear the node's data memory using the del() function.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && (*alst) && del)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
}
