/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:36:41 by ftothmur          #+#    #+#             */
/*   Updated: 2019/08/31 19:04:33 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function for the values of the input variables of the dividend and
** divisor (except for the divisor equal to zero) finds and assigns the quotient
** of the integer division and the remainder of the integer division. If the
** divisor is equal to zero, assigns INT_MAX to each variable by pointer.
*/

void	ft_div_mod(int devidend, int devider, int *div, int *mod)
{
	if (devider)
	{
		*div = devidend / devider;
		*mod = devidend % devider;
	}
	else
	{
		*div = INT_MAX;
		*mod = INT_MAX;
	}
	return ;
}
