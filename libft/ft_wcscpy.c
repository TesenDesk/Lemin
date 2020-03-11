/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcscpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:02:02 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/10 22:16:13 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Byte byte copies the characters of the source string to the destination
** string until the zero byte is found. After copying the zero byte, the
** function terminates.
**	Returns a pointer to the first argument.
*/

wchar_t		*ft_wcscpy(wchar_t *dst, const wchar_t *src)
{
	wchar_t	*sav;

	if (!dst || !src)
		return (NULL);
	sav = dst;
	if (dst != src)
		while ((*dst++ = *src++))
			;
	return (sav);
}
