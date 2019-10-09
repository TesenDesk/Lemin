/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:54:41 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:40:27 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		t1;
	size_t		t2;

	t1 = ft_strlen(haystack);
	t2 = ft_strlen(needle);
	if (*needle == 0)
		return ((char*)haystack);
	if (t1 < t2)
		return (NULL);
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, t2))
			return ((char*)haystack);
		++haystack;
	}
	return (NULL);
}
