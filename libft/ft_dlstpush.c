/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:56:38 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 17:35:38 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The address of the pointer to the first node in the linked list is passed
** to the function as the first argument, and the pointer to the newly created
** node of the linked list is passed by value as the second argument. It is
** required to make a new node first in the linked list, the parameter of which
** is transferred.
*/

void				ft_dlstpush(t_dlist **head, t_dlist *new)
{
	ft_dlstadd(head, new);
	return ;
}
