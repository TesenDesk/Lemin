/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:12:44 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/23 22:18:35 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstswap(t_dlist *fst, t_dlist *snd)
{
	void			*content;

	if (fst && snd)
	{
		content = fst->content;
		fst->content = snd->content;
		snd->content = content;
	}
	return ;
}
