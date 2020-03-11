/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:14:18 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/13 15:14:51 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	special case of ft_putstr_fd, in which the fd parameter is fixed by the
** value stdout == 1.
*/

void	ft_putwcs(wchar_t const *wcs)
{
	ft_putwcs_fd(wcs, STDOUT);
	return ;
}
