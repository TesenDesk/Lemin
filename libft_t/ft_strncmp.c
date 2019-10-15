/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:56:57 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:38:56 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
		return (0);
	while (n--)
	{
		c1 = *s1++;
		c2 = *s2++;
		if ((unsigned char)c1 != (unsigned char)c2 || !c1 || !c1)
			return ((int)(unsigned char)c1 - (unsigned char)c2);
	}
	return ((int)c1 - c2);
}
