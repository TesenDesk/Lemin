/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmerge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:06:50 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/20 16:08:25 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function adds all the nodes of src after dst.
*/

void				ft_dlstmerge(t_dlist **head_dst, t_dlist **head_src)
{
	t_dlist			*last_dst;
	t_dlist			*last_src;

	if (head_dst && head_src && *head_src && *head_dst != *head_src)
	{
		if (!*head_dst)
			*head_dst = *head_src;
		else
		{
			last_dst = (*head_dst)->prev;
			last_src = (*head_src)->prev;
			last_dst->next = (*head_src);
			(*head_src)->prev = last_dst;
			last_src->next = (*head_dst);
			(*head_dst)->prev = last_src;
		}
		*head_src = NULL;
	}
	return ;
}
