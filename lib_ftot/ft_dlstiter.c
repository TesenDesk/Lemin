/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:32:22 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/10 21:17:32 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

/*
** Apply the function from the second argument for each node in the linked list,
** starting with the one passed in by the first argument.
*/

void	ft_dlstiter(t_dlist *top, void (*f)(t_dlist *elem))
{
	t_dlist	*thelst;
	t_dlist	*nxtlst;

	thelst = top;
	if (top && f)
	{
		while (thelst != top)
		{
			nxtlst = thelst->next;
			(*f)(thelst);
			thelst = nxtlst;
		}
	}
	return ;
}
