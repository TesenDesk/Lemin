/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:38:46 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:22:59 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function passes a byte, and prints every single bit of it from low to
** high.
*/

static int			ft_checkbit(long long n, int position)
{
	return ((n & ((unsigned long long)1 << position)) != 0);
}

void				ft_print_bits(unsigned long long int n, int count)
{
	while (count--)
	{
		ft_putchar(ft_checkbit(n, count) + '0');
		if (!(count % 4 && count))
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return ;
}
