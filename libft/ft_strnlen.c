/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:54:57 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:54:58 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The return value is equal to the minimum of the string length and maxlen.
*/

size_t	ft_strnlen(const char *str, size_t maxlen)
{
	const char	*s;

	s = str;
	if (str && maxlen)
		while ((maxlen-- != 0) && (*s != '\0'))
			s++;
	return ((size_t)(s - str));
}
