/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:12:54 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/10 22:13:27 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates space for the argument string in the heap. Then, in the selected
** area, the line is copied as in the function ft_memcpy.
**	Returns a pointer to a copy of the argument.
*/

char		*ft_strdup(const char *str)
{
	char	*dp;
	size_t	size;

	if (!str || !(size = ft_strlen(str) + 1) ||
			!(dp = (char *)malloc(size * sizeof(char))))
		return (NULL);
	(void)ft_memcpy((void *)dp, (const void *)str, size * sizeof(char));
	return ((char *)dp);
}
