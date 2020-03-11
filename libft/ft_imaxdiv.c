/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxdiv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:06:27 by ftothmur          #+#    #+#             */
/*   Updated: 2019/08/31 19:05:59 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The div() function computes the value numer/denom (numerator/denominator).
** It returns a structure named div_t that contains two int members named quot
** (quotient) and rem (remainder).
*/

t_imaxdiv			ft_imaxdiv(intmax_t numer, intmax_t denom)
{
	t_imaxdiv result;

	if (denom)
	{
		result.quot = numer / denom;
		result.rem = numer % denom;
	}
	else
	{
		result.quot = INTMAX_MIN;
		result.rem = INTMAX_MIN;
	}
	return (result);
}
