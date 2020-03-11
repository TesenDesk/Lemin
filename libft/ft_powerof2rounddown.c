/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powerof2rounddown.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:45:28 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/02 20:29:24 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Finds the nearest not greater power of two for a given number.
*/

size_t	ft_powerof2rounddown(long long int nbr)
{
	if (!ft_ispowerof2(nbr))
	{
		nbr--;
		nbr |= nbr >> 1;
		nbr |= nbr >> 2;
		nbr |= nbr >> 4;
		nbr |= nbr >> 8;
		nbr |= nbr >> 16;
		if (SIZE_MAX - 0xffffffffU > 0)
			nbr |= nbr >> 32;
		nbr++;
		nbr >>= 1;
	}
	return (nbr);
}
