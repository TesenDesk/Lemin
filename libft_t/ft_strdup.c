/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:41:59 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 16:05:54 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*tmp;

	if (!(dest = (char*)malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (NULL);
	tmp = dest;
	while ((*dest++ = *src++))
		;
	return (tmp);
}
