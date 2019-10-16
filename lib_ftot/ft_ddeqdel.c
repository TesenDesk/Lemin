/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddeqdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:18:38 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 19:04:01 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

void			ft_ddeqdel(t_ddeq **ddeq, void (*delfunc)(void *, size_t))
{
	if (ddeq && *ddeq)
	{
		if (!delfunc)
			delfunc = &ft_delfunc_dummy;
		ft_dlstdel(&(*ddeq)->a, delfunc);
		ft_dlstdel(&(*ddeq)->b, delfunc);
		ft_memdel((void **)ddeq);
	}
	return ;
}
