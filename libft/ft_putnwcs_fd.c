/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwcs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:49:34 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/15 13:59:21 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function sequentially writes each character of the string to the file
** indicated by the file descriptor value.
*/

void	ft_putnwcs_fd(wchar_t const *wcs, int fd, size_t len)
{
	len = ft_wcsnlen(wcs, len);
	if (wcs)
		(void)write(fd, wcs, len * sizeof(wchar_t));
	return ;
}
