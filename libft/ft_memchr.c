/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:01:26 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 15:01:27 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Performs byte by byte, all bytlen bytes, from the string srcstr, comparing
** the current character (each time it is converted to an unsigned character)
** with argument c.
**	If the character c was found, then a pointer to the byte containing c is
** returned; otherwise, returns a pointer to NULL.11
*/

void	*ft_memchr(const void *str, int c, size_t size)
{
	const unsigned char	*s;

	if (str && size)
	{
		s = str;
		while (size--)
			if (*s++ == (unsigned char)c)
				return ((void *)(s - 1));
	}
	return (NULL);
}
