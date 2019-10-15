/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:13:27 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:29:42 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (n-- && (*(unsigned char*)s1++ == *(unsigned char*)s2++))
		;
	return (*((unsigned char*)--s1) - *((unsigned char*)--s2));
}
