/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:06:29 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/10 22:26:43 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates space for the argument string in the heap. Then, in the selected
** area, the line is copied as in the function ft_memcpy.
**	Returns a pointer to a copy of the argument.
*/

wchar_t		*ft_wcsdup(const wchar_t *str)
{
	wchar_t	*dp;
	size_t	size;

	if (!str || !(size = ft_wcslen(str) + 1) ||
			!(dp = (wchar_t *)malloc(size * sizeof(wchar_t))))
		return (NULL);
	(void)ft_memcpy((void *)dp, (const void *)str, size * sizeof(wchar_t));
	return ((wchar_t *)dp);
}
