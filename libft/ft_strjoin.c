/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:51:11 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:51:12 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Creates a string in the heap that is a concatenation of strings in which s1
** values precede s2.
**	Returns a pointer to the received string, or a pointer to NULL, in case of
** failure.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fshstr;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((fshstr = (char *)malloc((len1 + len2 + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(fshstr, s1, len1);
	ft_memcpy(fshstr + len1, s2, len2);
	*(fshstr + len1 + len2) = '\0';
	return (fshstr);
}
