/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:02:07 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/27 17:18:37 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks byte by byte all bytlen bytes to find out if there is at least one
** difference between the two argument vectors. If there are no differences, it
** returns 0, otherwise it returns the difference between the two first
** differing bytes, considering that they are of the unsigned char type.
** min -- minuend, sub -- subtrahend, dif -- difference, len -- bytlen
*/

int	ft_memcmp(const void *min, const void *sub, size_t size)
{
	int			dif;
	const char	*m;
	const char	*s;

	m = min;
	s = sub;
	dif = 0;
	if (min && sub && size && min != sub)
	{
		while (size--)
		{
			if (*m != *s)
			{
				dif = (unsigned char)*m - (unsigned char)*s;
				break ;
			}
			m++;
			s++;
		}
	}
	return (dif);
}
