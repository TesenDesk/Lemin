/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_sign_bit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:16:48 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/17 14:16:51 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The finction nullifies sign bit of the nbr passed as array of bytes. Due to
** nbrs can occupy 1 to 8 bytes at little endian x86 machine memory it is needed
** second argument of nbr size.
**	If nbr < 0 it is returned 1, or 0 otherwize.
*/

int					ft_remove_sign_bit(unsigned char *nbr_ar, int size)
{
	int				isminus;

	isminus = 0;
	if (CHAR_BYTES <= size || size <= INTMAX_BYTES)
	{
		isminus = (int)(!!((*(nbr_ar + size - 1) & CHAR_SGN_MASK)));
		if (isminus == 1)
			*(nbr_ar + size - 1) &= DEL_CHAR_SGN;
	}
	return (isminus);
}
