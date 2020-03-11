/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:37:03 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/10 22:14:14 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The return value is equal to the minimum of the string length and maxlen.
*/

size_t				ft_wcsnlen(const wchar_t *str, size_t maxlen)
{
	const wchar_t	*s;

	s = str;
	if (str && maxlen)
		while ((maxlen-- != 0) && (*s != '\0'))
			s++;
	return ((size_t)(s - str));
}
