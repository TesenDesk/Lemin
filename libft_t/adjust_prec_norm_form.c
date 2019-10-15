/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_prec_norm_form.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:42:34 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:49:30 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			adjust_fnum_prec(t_buf_struct *buf_s, t_dec_frac *l_num)
{
	if (B_AR_CUR.type == 'f')
		adjust_double_norm_form(l_num, B_AR_CUR.prec,
		(count_size_fnum(l_num->frac.l_num[l_num->frac.filled - 1]) +
		B_AR_CUR.ld_zeros), &(B_AR_CUR.ld_zeros));
	else if (B_AR_CUR.type == 'e')
		adjust_double_sci_form(buf_s, l_num);
}

void			norm_zero_prec(t_dec_frac *l_num, int index)
{
	if (check_for_fives2(&(l_num->frac), index,
			count_size_fnum(l_num->frac.l_num[index]),
			l_num->dec.l_num[0] % 10) > 0)
		rebuild_dec(l_num, 0);
	else
		l_num->frac.l_num[0] &= 0;
}

void			norm_zeros_equal_prec(t_dec_frac *l_num,
int index, int *ld_zeros)
{
	if (check_for_fives2(&(l_num->frac), l_num->frac.cur,
			count_size_fnum(l_num->frac.l_num[index]), 0) > 0)
	{
		l_num->frac.l_num[l_num->frac.cur] = 1;
		--(*ld_zeros);
	}
}

void			adjust_double_norm_form(t_dec_frac *l_num, int prec,
		int count_prec, int *ld_zeros)
{
	int			index;
	ULL			tmp_num;

	tmp_num = 0;
	l_num->frac.cur = l_num->frac.filled - 1;
	index = l_num->frac.cur;
	if (*ld_zeros > prec)
		return ;
	else if (prec == 0)
		norm_zero_prec(l_num, index);
	else if (*ld_zeros == prec)
		norm_zeros_equal_prec(l_num, index, ld_zeros);
	else if (count_prec >= prec)
		analize_frac_cell(l_num, count_prec - prec, ld_zeros, 1);
	else if (prec > 0)
	{
		while (count_prec < prec && --(l_num->frac.cur) >= 0)
			count_prec += 9;
		if (l_num->frac.cur >= 0)
			analize_frac_cell(l_num, count_prec - prec, ld_zeros, 0);
	}
}

int				is_zero_l_num_norm(t_long_num *l_num, int index)
{
	if (index >= 0)
	{
		while (index >= 0)
			if (l_num->l_num[index--] > 0)
				return (0);
	}
	return (1);
}
