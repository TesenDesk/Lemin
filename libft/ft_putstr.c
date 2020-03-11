/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:46:12 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:46:14 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	special case of ft_putstr_fd, in which the fd parameter is fixed by the
** value stdout == 1.
*/

void	ft_putstr(char const *str)
{
	ft_putstr_fd(str, STDOUT);
	return ;
}
