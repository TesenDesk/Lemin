/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:27:45 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/13 21:28:15 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	special case of ft_putstr_fd, in which the fd parameter is fixed by the
** value stdout == 1.
*/

void	ft_putnstr(char const *str, size_t len)
{
	ft_putnstr_fd(str, STDOUT, len);
	return ;
}
