/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:38:41 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:51:54 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		count_dec_frac_digs(t_long_num *l_num)
{
	size_t		i;
	ULL			temp;

	i = ((l_num->filled - 1) * 9);
	if (l_num->filled > 0)
	{
		temp = l_num->l_num[l_num->filled - 1];
		while ((temp /= 10) > 0)
			++i;
		++i;
	}
	else
		i = 1;
	return (i);
}

void		count_exp_pow(t_buf_struct *buf_s, t_dec_frac *l_num)
{
	if (!(l_num->dec.filled) & !(l_num->frac.filled))
		B_AR_CUR.exp_pow = 2;
	else if (l_num->dec.filled)
	{
		B_AR_CUR.exp_negative = 0;
		B_AR_CUR.exp_pow = count_dec_frac_digs(&(l_num->dec)) - 1;
	}
	else if (l_num->frac.filled)
	{
		B_AR_CUR.exp_negative = 1;
		B_AR_CUR.exp_pow = B_AR_CUR.ld_zeros + 1;
	}
}

ULL			ull_length(ULL num)
{
	size_t		i;

	i = 0;
	while (num)
	{
		i++;
		num /= 10;
	}
	return (i);
}
