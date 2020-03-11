/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddeqpush_b_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:19:25 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/20 15:56:54 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_ddeqpush_b_all(t_ddeq *ddeq)
{
	if (ddeq)
		ft_dlstmerge(&ddeq->b, &ddeq->a);
	return ;
}
