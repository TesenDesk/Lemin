/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:32:14 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:52:02 by mstygg           ###   ########.fr       */
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
