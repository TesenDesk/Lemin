/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:43:27 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:43:29 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copies byte by byte, all bytlen bytes, from the string srcstr to the string
** dststr until it encounters a symbol in the source string, after converting
** to the unsigned char equal to c, and then copying stops.
**	If the character c was found, then returns a pointer to the byte after the
** copy of c; otherwise, returns a pointer to NULL.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t size)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (dst && src && size)
	{
		d = dst;
		s = src;
		while (size-- != 0)
		{
			*d++ = *s++;
			if (*(s - 1) == (unsigned char)c)
				return (d);
		}
	}
	return (NULL);
}
