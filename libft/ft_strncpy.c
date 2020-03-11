/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:54:01 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:54:02 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Byte by byte copies the characters of the source string to the destination
** string until the source string ends or the maxlen bytes will be copied. If
** the source string length is less than maxlen, the remaining bytes are filled
** with a zero byte.
**	Returns a pointer to the first argument.
*/

char	*ft_strncpy(char *dst, const char *src, size_t maxlen)
{
	size_t	len;

	if (!dst || !src)
		return (NULL);
	if (maxlen > 0)
	{
		if (maxlen < (len = ft_strlen(src)))
			ft_memcpy((void *)dst, (const void *)src, maxlen);
		else
		{
			ft_memcpy((void *)dst, (const void *)src, len);
			ft_memset((void *)(dst + len), '\0', (maxlen - len));
		}
	}
	return (dst);
}
