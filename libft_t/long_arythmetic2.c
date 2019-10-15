/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arythmetic2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:48:41 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:52:29 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** t_long_num			*long_pow(t_long_num *l_unit, int exponent)
** {
** 	t_long_num			power_num1;
** 	t_long_num			res;
**
** 	res.l_num[0] = 1;
** 	res.filled = 1;
** 	long_copy(&power_num1, l_unit->l_num, l_unit->filled);
** 	if (exponent > 0)
** 		;
** 		 power_num1.l_num[0] = 2;
** 	else if (exponent < 0)
** 		exponent = -exponent;
** 	else
** 	{
** 		l_unit->l_num[0] = 1;
** 		l_unit->filled = 1;
** 		return (l_unit);
** 	}
** 	 if (exponent == 1)
** 	 return (l_unit);
** 	 else
** 	 {
** 	while (exponent > 0)
** 	{
** 		if (exponent & 1)
** 			long_mul(&res, &power_num1);
** 		long_mul(&power_num1, &power_num1);
** 		exponent >>= 1;
** 	}
** 	 }
** 	 long_mul(l_unit, &power_num1);
** 	long_copy(l_unit, res.l_num, res.filled);
** 	return (l_unit);
** }
*/

t_long_num			*long_pow(t_long_num *l_unit, int exponent)
{
	t_long_num			power_num1;

	(*l_unit).l_num[0] = 1;
	long_num_zero(power_num1.l_num, L_AR_SIZE);
	++((*l_unit).filled);
	if (exponent > 0)
		power_num1.l_num[0] = 2;
	else if (exponent < 0)
	{
		exponent = -exponent;
		power_num1.l_num[0] = 5;
	}
	else
		return (l_unit);
	power_num1.filled = 1;
	while (exponent)
	{
		if (exponent & 1)
			long_mul(l_unit, &power_num1);
		long_mul(&power_num1, &power_num1);
		exponent >>= 1;
	}
	return (l_unit);
}

ULL					*long_mul(t_long_num *l1, t_long_num *l2)
{
	size_t			i;
	size_t			j;
	ULL				cur;
	ULL				res[L_AR_SIZE];
	size_t			counter;

	i = 0;
	j = 0;
	cur = 0;
	counter = 0;
	long_num_zero(res, L_AR_SIZE);
	while (i < (*l1).filled)
	{
		while (j < (*l2).filled || cur)
		{
			cur += res[i + j] + (*l1).l_num[i] * (*l2).l_num[j];
			res[i + j++] = cur % LONG_BASE;
			cur /= LONG_BASE;
		}
		counter = i++ + j;
		j = 0;
	}
	(*l1).filled = counter;
	long_copy(l1, res, (*l1).filled);
	return ((*l1).l_num);
}

t_long_num			*long_short_mul(t_long_num *lnum, ULL mul_num)
{
	size_t		counter;
	size_t		cur_filled;
	ULL			temp_cur;
	ULL			temp_remain;

	counter = 0;
	cur_filled = (*lnum).filled;
	temp_cur = 0;
	temp_remain = 0;
	while ((counter < cur_filled) || temp_remain)
	{
		temp_cur = lnum->l_num[counter] * mul_num;
		(*lnum).l_num[counter] = temp_cur % LONG_BASE + temp_remain;
		temp_remain = temp_cur / LONG_BASE;
		++counter;
	}
	(*lnum).filled = counter;
	return (lnum);
}

t_long_num			*long_add(t_long_num *l_num, t_long_num *l_num2)
{
	size_t			pos;
	size_t			max_size;
	ULL				temp_cur;
	ULL				temp_remain;

	max_size = (((*l_num).filled > (*l_num2).filled) ?
				((*l_num).filled) : ((*l_num2).filled));
	(*l_num).filled = max_size;
	pos = 0;
	temp_cur = 0;
	temp_remain = 0;
	while (pos < max_size || temp_remain)
	{
		(*l_num).l_num[pos] += temp_remain +
				((pos < (*l_num2).filled) ? ((*l_num2).l_num[pos]) : (0));
		temp_remain = (*l_num).l_num[pos] >= LONG_BASE;
		if (temp_remain)
			(*l_num).l_num[pos] -= LONG_BASE;
		if (pos >= (*l_num).filled)
			++((*l_num).filled);
		++pos;
	}
	return (l_num);
}
