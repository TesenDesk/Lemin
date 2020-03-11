/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbinary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:30:10 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:30:12 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function checks whether this variable, which is supposed to have a copy
** of the contents of some file, has a zero byte, or the number of non-printable
** characters in the first BIN_CHECK bytes is more than 15% (as in grep() and
** diff() functions).
*/

int	ft_isbinary(void *buf, size_t size)
{
	const char	*str;
	size_t		check_size;

	str = buf;
	check_size = (size_t)ft_imin((int)size, (int)BIN_CHECK);
	if (buf)
		if (ft_strnlen(str, check_size) < (size_t)check_size)
			return (1);
	return (0);
}
