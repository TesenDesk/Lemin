/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:25:18 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/15 13:58:20 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function sequentially writes each character of the string to the file
** indicated by the file descriptor value.
*/

void	ft_putnstr_fd(char const *str, int fd, size_t len)
{
	len = ft_strnlen(str, len);
	if (str)
		(void)write(fd, str, len);
	return ;
}
