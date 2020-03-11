/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:51:48 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:51:50 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates space on the heap with the required size to fit the src and the
** final zero byte. The byte by byte content of the source string is played in
** the destination string. Function fills the destination string with the
** appropriate elements of the source string after converting each of them
** with a function passed by the pointer.
**	If successful, returns a pointer to the destination string, otherwise NULL.
*/

char	*ft_strmap(char const *src, char (*fptr)(char))
{
	char	*dst;
	char	*d;

	dst = NULL;
	if (src && fptr && (dst = (char *)ft_memalloc(ft_strlen(src) + 1)))
	{
		d = dst;
		while (*src != '\0')
		{
			*d = (*fptr)(*src++);
			d++;
		}
		*d = '\0';
	}
	return (dst);
}
