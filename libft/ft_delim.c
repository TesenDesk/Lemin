/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:24:20 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:24:23 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function ft_delim() takes a pointer to the place 'line' where the result
** selecting the word from the string 'str' by the delimiter 'c' will be
** written.
*/

char	*ft_delim(char **line, char *str, char c)
{
	char	*top;
	char	*tip;
	int		ofset;

	if (!(top = str))
		return (NULL);
	ofset = 1;
	if (!(tip = ft_strchr(top, c)))
	{
		tip = top + ft_strlen(top);
		ofset = 0;
	}
	if (!(*line = ft_strsub(top, 0, tip - top)))
		return (NULL);
	return (!ofset || !*(tip + 1) ? NULL : ++tip);
}
