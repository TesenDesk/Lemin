/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:46:29 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/13 15:09:41 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function sequentially writes each character of the string to the file
** indicated by the file descriptor value.
*/

void	ft_putstr_fd(wchar_t const *wcs, int fd)
{
	int	len;

	if (s)
	{
		len = ft_wcslen(s);
		(void)write(fd, s, len * sizeof(wchar_t));
	}
	return ;
}
