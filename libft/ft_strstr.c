/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:56:09 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:56:13 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The case of ft_strnstr in which size does not affect the result.
*/

char	*ft_strstr(const char *dst, const char *src)
{
	return (ft_strnstr(dst, src, SIZE_MAX - 1));
}
