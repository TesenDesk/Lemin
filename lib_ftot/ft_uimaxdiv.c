/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxdiv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:06:27 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 20:11:58 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

/*
**	The div() function computes the value numer/denom (numerator/denominator).
** It returns a structure named div_t that contains two int members named quot
** (quotient) and rem (remainder).
*/

t_uimaxdiv			ft_uimaxdiv(uintmax_t numer, uintmax_t denom)
{
	t_uimaxdiv result;

	if (denom)
	{
		result.quot = numer / denom;
		result.rem = numer % denom;
	}
	else
	{
		result.quot = UINTMAX_MAX;
		result.rem = UINTMAX_MAX;
	}
	return (result);
}
