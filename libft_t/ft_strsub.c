/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:20:51 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:40:32 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	i = 0;
	if (!(new_s = (char*)malloc(len + 1)) || !s)
		return (NULL);
	while (i < len)
	{
		*(new_s + i) = *(s + start + i);
		++i;
	}
	*(new_s + i) = '\0';
	return (new_s);
}
