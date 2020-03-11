/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udiv_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:06:27 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/06 23:07:06 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The div() function computes the value numer/denom (numerator/denominator).
** It returns a structure named div_t that contains two int members named quot
** (quotient) and rem (remainder).
*/

t_udiv			ft_udiv_struc(unsigned int numer, unsigned int denom)
{
	t_udiv result;

	if (denom)
	{
		result.quot = numer / denom;
		result.rem = numer % denom;
	}
	else
	{
		result.quot = UINT_MAX;
		result.rem = UINT_MAX;
	}
	return (result);
}
