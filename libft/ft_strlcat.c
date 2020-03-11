/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:53:06 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:53:08 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The buffer size is the third argument. The function concatenates as many
** bytes of the source string in after the destination string as there is in
** the difference of the buffer and the length of the destination string
** within the buffer and one zero byte to complete the resulting string.
** Negative difference values are considered equal to 0.
**	The function returns the sum of the minimum of two values between the
** length of the destination string and the size of the buffer and the
** length of the source string.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	nbr;
	size_t	lft;

	if (!dst || !src)
		return (0);
	nbr = ft_strnlen(dst, size);
	if ((lft = (size - nbr)) == 0)
		return (nbr + ft_strlen(src));
	(void)ft_memcpy(dst + nbr, src, lft = ft_strnlen(src, lft - 1));
	*(dst + nbr + lft) = '\0';
	return (nbr + ft_strlen(src));
}
