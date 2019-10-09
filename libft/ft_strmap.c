/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:31:11 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:38:38 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		*(n_str + i) = f(*(s + i));
		++i;
	}
	*(n_str + i) = '\0';
	return (n_str);
}
