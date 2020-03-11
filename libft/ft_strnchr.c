/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:04:21 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 15:04:22 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Character by character scans first size elements of the string, including
** the zero byte, until it finds the character it is looking for.
**	If found, then returns a pointer to it, otherwise returns a pointer to NULL.
*/

char	*ft_strnchr(const char *str, int c, size_t size)
{
	while ((*str != c) && size)
	{
		if (*str == '\0')
			break ;
		str++;
		size--;
	}
	if ((*str != c) && !size)
		return (NULL);
	return ((char *)str);
}
