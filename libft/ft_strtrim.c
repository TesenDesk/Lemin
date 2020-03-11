/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:56:41 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:56:45 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Selects such a substring src, which has no whitespace at the beginning or
** at the end. Allocates space in the heap for this such a substring and the end
** character (zero byte). Copies the substring to the selected place. The
** incoming string must exist.
**	Returns a pointer to the received copy, or to NULL in case of failure.
*/

char	*ft_strtrim(char const *src)
{
	char const	*start;
	char const	*stop;
	char		*dst;

	dst = NULL;
	if (src)
	{
		start = src;
		while (ft_isspace((int)(*start)))
			start++;
		if ((stop = src + ft_strlen(src)) - start)
			while (ft_isspace((int)(*(--stop))))
				;
		dst = (char *)ft_strsub(src, start - src, stop - start == 0 \
			? 0 : stop - start + 1);
	}
	return (dst);
}
