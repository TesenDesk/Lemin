/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwcs_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:12:12 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/13 15:23:52 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function sequentially writes each character of the string to the file
** indicated by the file descriptor value.
*/

void	ft_putwcs_fd(wchar_t const *wcs, int fd)
{
	int	len;

	if (wcs)
	{
		len = ft_wcslen(wcs);
		(void)write(fd, wcs, len * sizeof(wcs));
	}
	return ;
}
