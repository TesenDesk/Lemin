/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddeqpush_b_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:19:25 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 19:03:50 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

void			ft_ddeqpush_b_all(t_ddeq *ddeq)
{
	t_dlist		*curr;

	if (ddeq && (curr = ddeq->a))
		while (ddeq->a)
			ft_ddeqpush_b(ddeq);
	return ;
}
