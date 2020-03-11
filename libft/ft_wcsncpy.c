/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:27:44 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/10 22:19:02 by ftothmur         ###   ########.fr       */
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

wchar_t		*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t maxlen)
{
	size_t	len;

	if (!dst || !src)
		return (NULL);
	if (maxlen > 0)
	{
		if (maxlen < (len = ft_wcslen(src)))
			ft_memcpy((void *)dst, (const void *)src,
					maxlen * sizeof(wchar_t));
		else
		{
			ft_memcpy((void *)dst, (const void *)src, len * sizeof(wchar_t));
			ft_memset((void *)(dst + len), L'\0',
					(maxlen - len) * sizeof(wchar_t));
		}
	}
	return (dst);
}
