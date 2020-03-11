/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:45:55 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:45:56 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function writes the incoming character to the file defined by the file
** descriptor.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}
