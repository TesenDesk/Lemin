/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:02:31 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:39:01 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	src_size;
	char	*tmp;

	src_size = ft_strlen(src);
	if (!len)
		return (dst);
	if (len < src_size)
	{
		tmp = dst;
		tmp = ft_memcpy(dst, src, len);
		return (tmp);
	}
	tmp = ft_memcpy(dst, src, src_size);
	dst += src_size;
	len -= src_size;
	while (len--)
		*dst++ = '\0';
	return (tmp);
}
