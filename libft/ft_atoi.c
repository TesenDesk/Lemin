/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:18:24 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/04 00:34:54 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	num;
	int		sign;
	long	check;

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
