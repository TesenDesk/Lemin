/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:52:44 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:52:45 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates space on the heap with the required size to fit the src and the
** final zero byte. The byte by byte content of the source string is played in
** the destination string. Functions and fills the destination line with the
** corresponding elements of the source line after each of them is converted
** by the function passed by the pointer. The first argument of the function
** on the pointer is the index of the string element passed to it.
**	If successful, returns a pointer to the destination string, otherwise NULL.
*/

char	*ft_strmapi(char const *src, char (*fptr)(unsigned int, char))
{
	char	*dst;
	char	*d;

	dst = NULL;
	if (src && fptr && (dst = (char *)ft_memalloc(ft_strlen(src) + 1)))
	{
		d = dst;
		while (*src != '\0')
		{
			*d = (*fptr)(d - dst, *src++);
			d++;
		}
		*d = '\0';
	}
	return (dst);
}
