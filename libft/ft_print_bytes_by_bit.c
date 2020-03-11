/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bytes_by_bit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:46:53 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:42:01 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function prints every byte of memory from low to high by every single
** bit.
*/

void				ft_print_bytes_by_bit(void *bytes, size_t size,
		int byte_delimiter)
{
	char			*ar;
	size_t			byte;

	if (bytes && size)
	{
		ar = (char *)bytes;
		byte = 0;
		while (byte < size)
		{
			ft_print_bits(*(ar + byte++));
			if (byte_delimiter)
				ft_putchar(' ');
		}
	}
	return ;
}
