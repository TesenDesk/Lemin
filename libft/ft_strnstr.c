/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:40:19 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:39:20 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		t1;
	size_t		t2;

	t1 = ft_strlen(haystack);
	t2 = ft_strlen(needle);
	if (*needle == 0)
		return ((char*)haystack);
	if ((t1 < t2) || len < t2)
		return (NULL);
	while (len && *haystack)
	{
		if (!ft_strncmp(haystack, needle, t2) && len >= t2)
			return ((char*)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
