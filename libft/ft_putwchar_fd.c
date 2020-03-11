/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:34:32 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/10 22:34:36 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function writes the incoming character to the file defined by the file
** descriptor.
*/

void	ft_putwchar_fd(wchar_t c, int fd)
{
	write(fd, &c, 1 * sizeof(wchar_t));
	return ;
}
