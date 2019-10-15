/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:26:42 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/04 13:52:05 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	t1;
	size_t	t2;

	t1 = ft_strlen(dst);
	t2 = ft_strlen(src);
	if (t1 >= size)
		return (size + t2);
	dst += t1;
	--size;
	if (t1 + t2 > size)
	{
		ft_memcpy(dst, src, size - t1);
		*(dst + size - t1) = 0;
	}
	else if (t1 + t2 <= size)
	{
		ft_memcpy(dst, src, t2);
		*(dst + t2) = 0;
	}
	return (t1 + t2);
}
