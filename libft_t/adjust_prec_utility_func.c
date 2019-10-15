/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_prec_utility_func.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:13:09 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:49:53 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				check_for_fives2(t_long_num *l_num, int index, int d_p,
		ULL first_dig)
{
	ULL			tmp_num;

	tmp_num = l_num->l_num[index];
	if (index < 0)
		return (0);
	if ((tmp_num % ft_pow(10, d_p) - tmp_num % ft_pow(10,
			d_p - 1)) / ft_pow(10, d_p - 1) > 5)
		return (1);
	else if ((tmp_num % ft_pow(10, d_p) - tmp_num %
	ft_pow(10, d_p - 1)) / ft_pow(10, d_p - 1) < 5)
		return (0);
	else
	{
		tmp_num = tmp_num % ft_pow(10, d_p - 1);
		if (tmp_num > 0 || !(is_zero_l_num_norm(l_num, index - 1)) ||
		first_dig % 2 == 1)
			return (1);
		return (0);
	}
}

int				check_for_nines(ULL tmp_num)
{
	int			size_num;

	size_num = count_size_fnum(tmp_num);
	if (size_num == 1)
		return (tmp_num == 9) ? (1) : (0);
	else if (size_num == 2)
		return (tmp_num == 99) ? (1) : (0);
	else if (size_num == 3)
		return (tmp_num == 999) ? (1) : (0);
	else if (size_num == 4)
		return (tmp_num == 9999) ? (1) : (0);
	else if (size_num == 5)
		return (tmp_num == 99999) ? (1) : (0);
	else if (size_num == 6)
		return (tmp_num == 999999) ? (1) : (0);
	else if (size_num == 7)
		return (tmp_num == 9999999) ? (1) : (0);
	else if (size_num == 8)
		return (tmp_num == 99999999) ? (1) : (0);
	else
		return (tmp_num == 999999999) ? (1) : (0);
}

int				check_for_ones(ULL tmp_num)
{
	int			size_num;

	size_num = count_size_fnum(tmp_num);
	if (size_num == 1)
		return (tmp_num == 1) ? (1) : (0);
	else if (size_num == 2)
		return (tmp_num == 10) ? (1) : (0);
	else if (size_num == 3)
		return (tmp_num == 100) ? (1) : (0);
	else if (size_num == 4)
		return (tmp_num == 1000) ? (1) : (0);
	else if (size_num == 5)
		return (tmp_num == 10000) ? (1) : (0);
	else if (size_num == 6)
		return (tmp_num == 100000) ? (1) : (0);
	else if (size_num == 7)
		return (tmp_num == 1000000) ? (1) : (0);
	else if (size_num == 8)
		return (tmp_num == 10000000) ? (1) : (0);
	else
		return (tmp_num == 100000000) ? (1) : (0);
}

ULL				find_first_l_num(t_dec_frac *l_num)
{
	if (l_num->dec.filled > 0)
		return (l_num->dec.l_num[l_num->dec.filled - 1]);
	else if (l_num->frac.filled > 0)
		return (l_num->frac.l_num[l_num->frac.filled - 1]);
	else
		return (ULL)(0);
}

void			clear_lnum_df(t_long_num *l_num, int index)
{
	while (index >= 0)
		l_num->l_num[index--] &= 0;
}
