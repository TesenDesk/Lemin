/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:15:12 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:29:57 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_memjoin(char *s1, char *s2, size_t t1, size_t t2)
{
	char	*new_s;
	char	*tmp;

	if ((!s1 && !s2))
		return (NULL);
	if (!s1)
	{
		if (!(new_s = (char*)malloc(t2 * sizeof(char))))
			return (NULL);
		return (ft_memcpy(new_s, s2, t2));
	}
	if (!s2)
	{
		if (!(new_s = (char*)malloc(t1 * sizeof(char))))
			return (NULL);
		return (ft_memcpy(new_s, s1, t1));
	}
	if (!(new_s = (char*)malloc((t1 + t2) * sizeof(char))))
		return (NULL);
	tmp = new_s;
	ft_memcpy(new_s, s1, t1);
	new_s += t1;
	while (t2--)
		*new_s++ = *s2++;
	return (tmp);
}
