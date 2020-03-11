/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:51:34 by ftothmur          #+#    #+#             */
/*   Updated: 2019/08/31 20:40:46 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The return value is equal to the minimum of the string length and maximum
** of the size_t size.
*/

size_t	ft_strlen(const char *str)
{
	return (ft_strnlen(str, SIZE_MAX - 1));
}
