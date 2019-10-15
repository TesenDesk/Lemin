/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:41:36 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:37:24 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char ch;

	ch = c;
	if (ch == 0)
		return ((char*)(s + ft_strlen(s)));
	if (!s)
		return (NULL);
	while (*s && *s != ch)
		++s;
	return (*s) ? ((char*)s) : (NULL);
}
