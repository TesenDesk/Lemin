/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:20:29 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/27 17:24:19 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	r - for rear, moving backward, to cmp little-endian nbrs.
**
** Checks byte by byte all bytlen bytes to find out if there is at least one
** difference between the two argument vectors. If there are no differences, it
** returns 0, otherwise it returns the difference between the two first
** differing bytes, considering that they are of the unsigned char type.
** min -- minuend, sub -- subtrahend, dif -- difference, len -- bytlen
*/

int	ft_intrcmp(const void *min, const void *sub)
{
	return (ft_memrcmp(min, sub, sizeof(int)));
}
