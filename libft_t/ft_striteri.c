/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:21:57 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:38:17 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	size;
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		f(i, s + i);
		++i;
	}
}
