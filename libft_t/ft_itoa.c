/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:23:15 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:28:41 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	arr_size(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		++i;
	while (n /= 10)
		++i;
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char	*arr;
	size_t	size;
	long	num;

	num = n;
	size = arr_size(n);
	if (!(arr = (char*)ft_memalloc(size-- + 1)))
		return (NULL);
	if (!num)
	{
		*arr = '0';
		return (arr);
	}
	if (num < 0)
	{
		*arr = '-';
		num *= -1;
	}
	while (num)
	{
		*(arr + size--) = num % 10 + '0';
		num /= 10;
	}
	return (arr);
}
