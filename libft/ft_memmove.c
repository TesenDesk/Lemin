/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:44:44 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/11 17:15:50 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Copies byte by byte, total bytlen bytes, from the srcstr string to the
** dststr string. It is protected from the case of intersection of lines.
**	Returns a pointer to the first argument.
*/

static void	*ft_memrcpy(void *dst, const void *src, size_t size)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst + size - 1;
	s = (unsigned char *)src + size - 1;
	while (size--)
		*d-- = *s--;
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t size)
{
	if (!dst || !src)
		return (NULL);
	if (dst <= src ||
			(unsigned const char *)dst >=
			((unsigned const char *)src + size))
		(void)ft_memcpy(dst, src, size);
	else
		(void)ft_memrcpy(dst, src, size);
	return (dst);
}
