/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:56:43 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/18 18:06:59 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*ft_dlstnew_ptr(void *content)
{
	t_dlist		*new;

	if (!(new = (t_dlist *)ft_memalloc(1 * sizeof(t_dlist))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = content;
		new->content_size = sizeof(new->content);
	}
	new->next = new;
	new->prev = new;
	return (new);
}
