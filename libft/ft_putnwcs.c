/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:53:17 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/15 13:53:41 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	special case of ft_putstr_fd, in which the fd parameter is fixed by the
** value stdout == 1.
*/

void	ft_putnwcs(wchar_t const *str, size_t len)
{
	ft_putnwcs_fd(str, STDOUT, len);
	return ;
}
