/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:55:37 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/13 14:59:15 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates a place in the heap of len size (len of string) + 1 (for zero
** byte) and fills it with zero bytes.
**	If successful, returns a pointer to the selected array, otherwise NULL.
*/

wchar_t	*ft_wcsnew(size_t len)
{
	wchar_t *str;

	str = NULL;
	if ((str = (wchar_t *)malloc((len + 1) * sizeof(wchar_t))))
		(void)ft_memset(str, '\0', (len + 1) * sizeof(wchar_t));
	return (str);
}
