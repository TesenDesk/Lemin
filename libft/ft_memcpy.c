/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:01:50 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 15:01:52 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copies byte-byte, total bytlen bytes, from the string passed in the second
** argument to the string passed in the first argument.
**	Not protected from intersecting lines or the passed string does not ends
** with a '\0', or even arguments exist, or bytlen != 0.
**	Returns a pointer to the first argument.
*/

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst && src && dst != src)
	{
		d = dst;
		s = src;
		while (len-- != 0)
			*d++ = *s++;
	}
	return (dst);
}
