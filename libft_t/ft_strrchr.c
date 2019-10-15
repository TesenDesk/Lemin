/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:09:14 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:43:15 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		count;

	ch = c;
	if (ch == 0)
		return ((char*)(s + ft_strlen(s)));
	if (!s)
		return (NULL);
	count = ft_strlen(s);
	s += count - 1;
	while (count && *s != ch)
	{
		--s;
		--count;
	}
	return (count) ? ((char*)s) : (NULL);
}
