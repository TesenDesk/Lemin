/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:55:10 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:55:11 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 	In the string, dst searches for the occurrence of the string src in the
** first size characters.
**	Returns:
** If src is empty, then the pointer to dst.
** If the required substring is not found, then a pointer to NULL.
** Otherwise, a pointer to a substring.
**
**	First, the conditions for missing arguments are processed by reference. If
** they are not there, and also if the string dst, where the search will be
** performed, is empty, or the number of characters for the search, size is 0,
** and also if the string src, whose entry in dst is searched, does not fit
** there, in all these Cases will return a null pointer. (By end symbol from
** dst). The same result will be if there is no substring in dst equal to src
** within the first size characters.
**	The function in the loop first searches for the nearest occurrence of the
** first src character in the given dst part (the crt character, the current
** one). Every time when we find it, it checks whether src enters dst from this
** viewing point.
*/

char	*ft_strnstr(const char *dst, const char *src, size_t size)
{
	char const	*end;
	char const	*crt;
	size_t		len;

	if (!(*src))
		return ((char *)dst);
	if (!dst || !src || !size || !(*dst) ||
			((end = dst + ft_strnlen(dst, size) - ft_strlen(src)) < dst))
		return (NULL);
	crt = dst;
	len = ft_strlen(src);
	while (1)
	{
		if (!(crt = ft_strnchr(crt, *src, end - crt)) || (crt > end))
			break ;
		if (!ft_strncmp(src, crt, len))
			return ((char *)crt);
		crt++;
	}
	return (NULL);
}
