/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:44:29 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 17:33:48 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	It finds the last node of the linked list, and returns pointer to it.
*/

void				ft_dlstpush_back(t_dlist **head, t_dlist *new)
{
	ft_dlstaddtip(head, new);
	return ;
}
