/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:49:44 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:49:45 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Byte by byte the corresponding characters of the two lines are compared,
** until a difference is found or the ends of the lines are reached.
**	If a difference has been found, returns the difference in lexigographic
** order between the two characters converted to the unsigned char that the
** process has stopped at, otherwise 0.
*/

int	ft_strcmp(const char *minuend, const char *subtrahend)
{
	return (ft_strncmp(minuend, subtrahend, SIZE_MAX));
}
