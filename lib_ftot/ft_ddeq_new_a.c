/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddeq_new_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:17:00 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/17 13:55:27 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

t_dlist			*ft_ddeq_new_a(t_ddeq **ddeq,
					void *content, ssize_t content_size)
{
	t_dlist		*new_a;

	new_a = NULL;
	if (ddeq)
	{
		if (!*ddeq)
			if (!(*ddeq = ft_ddeqnew(NULL)))
				return (NULL);
		if (content && content_size)
		{
			if ((*ddeq)->b)
				new_a = ft_dlstpop(&(*ddeq)->b);
			else if (!(new_a = ft_dlstnew(content, content_size)))
				return (NULL);
			ft_dlstpush_back(&(*ddeq)->a, new_a);
		}
	}
	return (new_a);
}
