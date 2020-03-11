/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:45:08 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/10 22:13:57 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The return value is equal to the minimum of the string length and maximum
** of the size_t size.
*/

size_t			ft_wcslen(const wchar_t *str)
{
	return (ft_wcsnlen(str, SIZE_MAX - 1));
}
