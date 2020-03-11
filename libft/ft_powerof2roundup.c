/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powerof2roundup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:45:28 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:45:29 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Finds the nearest greater power of two for a given number.
*/

size_t	ft_powerof2roundup(long long int nbr)
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
	}
	return (nbr);
}
