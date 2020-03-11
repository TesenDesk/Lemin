/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:53:44 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:53:45 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	As long as the viewing length is greater than 0 byte by byte, the
** corresponding characters of the two lines are compared until a difference
** is found or the ends of the lines are reached.
**	If a difference has been found, returns the difference in lexigographic
** order between the two characters converted to the unsigned char that the
** process has stopped at, otherwise 0.
*/

int	ft_strncmp(const char *min, const char *sub, size_t len)
{
	if (!min || !sub)
		return (-1);
	while (len != 0)
	{
		if ((*min != *sub) || (*min == '\0'))
			break ;
		min++;
		sub++;
		len--;
	}
	return (len > 0 ? ((unsigned char)(*min) - (unsigned char)(*sub)) : 0);
}
