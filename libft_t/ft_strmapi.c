/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:39:05 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:38:46 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*n_str;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	if (!(n_str = (char*)malloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		*(n_str + i) = f((unsigned int)i, *(s + i));
		++i;
	}
	*(n_str + i) = '\0';
	return (n_str);
}
