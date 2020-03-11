/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:35:05 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:23:24 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstswap(t_list **head, t_list *first, t_list *second)
{
	int				size;
	t_list			*prev_first;
	t_list			*prev_second;

	if (!head)
		return ;
	size = ft_lstsize(*head);
	if (size < 2 || !first || !second ||
			!(prev_first = ft_lstfind_prev(head, (void *)first)) ||
			!(prev_second = ft_lstfind_prev(head, (void *)second)))
		return ;
	return ;
}
