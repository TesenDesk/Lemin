/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:55:39 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/05 00:33:36 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atol(const unsigned char *str)
{
	long long	num;
	char		sign;
	long long	check;

	num = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		check = num;
		num *= 10;
		if (num / 10 != check)
			return (sign < 0) ? (0) : (-1);
		num += (*str++ - '0');
		if (num < 0)
			return (sign < 0) ? (0) : (-1);
	}
	return (num * sign);
}
