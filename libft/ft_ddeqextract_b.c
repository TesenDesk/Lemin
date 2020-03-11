/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddeqextract_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:22:10 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/02 23:29:30 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_ddeqextract_b(t_ddeq *ddeq, t_dlist *from_a)
{
	t_dlist			*to_b;

	to_b = ft_dlstextract(&ddeq->a, from_a);
	ft_dlstpush_back(&ddeq->b, to_b);
	return ;
}
