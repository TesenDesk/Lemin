/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:48:37 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:48:38 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	A special case of ft_strncat, in which the length indicator does not
** matter.
*/

char	*ft_strcat(char *dst, const char *src)
{
	return (ft_strncat(dst, src, SIZE_MAX - 1));
}
