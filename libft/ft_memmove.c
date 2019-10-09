/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:41:08 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:30:02 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#	define ABS(value) (value > 0) ? (value) : (-value)

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	if (!len)
		return (dst);
	if (!dst && !src)
		return (NULL);
	tmp = dst;
	if ((ABS((src - dst)) < (long)len) && ((dst - src) > 0))
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
			*(char*)dst-- = *(char*)src--;
		return (tmp);
	}
	while (len--)
		*(char*)dst++ = *(char*)src++;
	return (tmp);
}
