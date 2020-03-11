/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:55:24 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:55:26 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Character by character scans the string, including the zero byte, to find
** the most recent occurrence of the search character.
**	If found, then returns a pointer to it, otherwise returns a pointer to
** NULL.
*/

char	*ft_strrchr(const char *str, int c)
{
	char const	*sav;

	if (!str)
		return (NULL);
	sav = str + ft_strlen(str);
	while (*sav != c)
	{
		if (sav == str)
		{
			sav = NULL;
			break ;
		}
		sav--;
	}
	return ((char *)sav);
}
