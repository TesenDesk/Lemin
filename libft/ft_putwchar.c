/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:28:34 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/10 22:28:51 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This is a special case of the function ft_putchar_fd, for which the file
** descriptor parameter is fixed in the state STDOUT == 1.
*/

void	ft_putwchar(wchar_t c)
{
	ft_putwchar_fd(c, STDOUT);
	return ;
}
