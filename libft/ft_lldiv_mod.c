/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldiv_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:36:41 by ftothmur          #+#    #+#             */
/*   Updated: 2019/08/31 19:05:13 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function for the values of the input variables of the dividend and
** divisor (except for the divisor equal to zero) finds and assigns the quotient
** of the integer division and the remainder of the integer division. If the
** divisor is equal to zero, assigns LLONG_MIN to each variable by pointer.
**	t_lli stands for long long int type.
*/

void	ft_lldiv_mod(t_lli devidend, t_lli devider, t_lli *div, t_lli *mod)
{
	if (devider)
	{
		*div = devidend / devider;
		*mod = devidend % devider;
	}
	else
	{
		*div = LLONG_MIN;
		*mod = LLONG_MIN;
	}
	return ;
}
