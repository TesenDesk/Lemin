/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:44:52 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/15 18:56:51 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function searches in the specified beginning of *head and the current
** position of *curr in the linked list, find the previous node, if it exists,
** returning a pointer to it, otherwise - a pointer to NULL.
*/

t_list		*ft_lstfind_prev(t_list *head, t_list *curr)
{
	t_list	*finding;

	return (finding = ft_lstfind(head, (void *)curr, ft_lstcmp_next));
}
