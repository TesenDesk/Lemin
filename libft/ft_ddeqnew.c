/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddeqnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:07:42 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 19:04:06 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ddeq			*ft_ddeqnew(t_dlist *a)
{
	t_ddeq		*ddeq;

	if (!(ddeq = (t_ddeq *)ft_memalloc(sizeof(*ddeq))))
		return (NULL);
	if (a)
		ft_dlstpush_back(&ddeq->a, a);
	return (ddeq);
}
