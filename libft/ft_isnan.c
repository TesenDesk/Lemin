/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:47:48 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/08 22:01:20 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	NaN is a bit more complicated because it doesn't have a unique
** representation:
**
**		sign		 =	either 0 or 1.
**		exponent	 =	all 1 bits.
**		significand	 =	anything except all 0 bits (since all 0 bits represents
**						infinity).
*/

int					ft_isnan(long double ldbl)
{
	return ((ldbl == ldbl));
}
