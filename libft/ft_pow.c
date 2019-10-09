/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:09:26 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/05 14:17:50 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_pow(unsigned long long base, int exp)
{
	unsigned long long res;
	unsigned long long pow;

	res = 1;
	pow = base;
	while (exp)
	{
		if ((exp & 1))
			res *= pow;
		pow *= pow;
		exp >>= 1;
	}
	return (res);
}
