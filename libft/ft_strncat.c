/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:53:29 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:53:30 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Starting at the end of the destination line, copies at most nbr bytes of
** the source string, whichever is shorter: source length or nbr. To result
** adds zero byte.
**	Returns a pointer to the string of the first argument.
*/

char	*ft_strncat(char *dst, const char *src, size_t nbr)
{
	size_t	len1;
	size_t	len2;
	size_t	dif;

	if (!dst || !src)
		return (NULL);
	if ((nbr > 0))
	{
		len1 = ft_strlen(dst);
		len2 = ft_strlen(src);
		dif = (nbr > len2 ? len2 : nbr);
		len2 = ft_strlen(src);
		(void)ft_memcpy((void *)(dst + len1), (const void *)src, dif);
		*(dst + len1 + dif) = '\0';
	}
	return (dst);
}
