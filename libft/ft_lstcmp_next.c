/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmp_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:36:15 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:36:18 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function checks whether the 'next' field of the first node indicates the
** node given by the second argument, returning 0 if it matches.
*/

int	ft_lstcmp_next(t_list *node1, void *node2)
{
	return (node1->next != node2);
}
