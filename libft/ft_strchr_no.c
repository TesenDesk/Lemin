/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_no.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:49:04 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:49:05 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	In the string str and its zero byte, it searches for a character that
** differs from c.
**	If the search character was not found, returns NULL,
** otherwise the pointer to a different character within the string.
*/

char	*ft_strchr_no(const char *str, int c)
{
	if (!str || !*str)
		return (NULL);
	while ((*str == c))
		str++;
	if (!(*str))
		return (NULL);
	return ((char *)str);
}
