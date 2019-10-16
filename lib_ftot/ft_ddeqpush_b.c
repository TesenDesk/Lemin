/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddeqpush_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:19:57 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 19:03:44 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

void			ft_ddeqpush_b(t_ddeq *ddeq)
{
	t_dlist		*curr;

	if (ddeq && (curr = ddeq->a))
		ft_dlstpush(&ddeq->b, ft_dlstpop(&curr));
	return ;
}
