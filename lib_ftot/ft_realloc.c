/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:47:08 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/17 13:55:27 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

/*
** The function is similar to realloc(), but it takes three arguments. The
** third argument is necessary, because outside the heap management manager we
** cannot know the size of the previously allocated memory.
**	In any case, buf1 at the end of all actions will be released. 1. If only the
** size of the output memory cell is true, this behavior of this function is
** equal to malloc(). 2. If all three parameters are not zero, memory size2
** will be allocated first, and if it succeeds, the smaller of the size values
** used to copy data from buf1 to the new memory location. Then buf1 is set to
** zero byte.
**	A pointer to the newly created memory will be returned; if it exists, it is
** different from the pointer to 0.
*/

void	*ft_realloc(void *buf1, size_t size1, size_t size2)
{
	void	*buf2;

	buf2 = NULL;
	if ((size2 && size1 && buf1) || (size2 && !size1 && !buf1))
		buf2 = ft_memalloc(size2);
	if (buf1 && buf2 && size1 && size2)
		(void)ft_memcpy(buf2, buf1, size1 > size2 ? size2 : size1);
	ft_memdel(&buf1);
	return (buf2);
}
