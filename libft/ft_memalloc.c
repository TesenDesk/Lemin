/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:43:11 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:43:12 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	If the size is greater than 0 (malloc (0) is not defined), then it tries
** to determine the place on the heap for a given number of bytes.
**	If successful, returns a pointer to the given area selected in the heap,
** otherwise returns NULL.
*/

void	*ft_memalloc(size_t size)
{
	void *str;

	str = NULL;
	if ((size > 0) && (str = (void *)malloc(size)))
		(void)ft_memset(str, 0, size);
	return (str);
}
