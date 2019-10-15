/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_into_buf_ldouble_utilities.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:17:49 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:53:41 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_sci_exp_zero_i(t_buf_struct *buf_s, t_dec_frac *l_num,
		int index, int count_prec)
{
	int		zero_i;

	zero_i = (index < (int)(l_num->dec.filled - 1)) ? (9 -
	count_size_fnum(l_num->dec.l_num[index])) : (0);
	if (l_num->dec.l_num[index] == 0)
		zero_i = 9;
	if (count_prec + zero_i > B_AR_CUR.prec)
		zero_i = 9 - (count_prec + zero_i - B_AR_CUR.prec);
	return (zero_i);
}

int			adjust_sci_exp_lnum_cell(t_buf_struct *buf_s,
		t_dec_frac *l_num, int index, int *count_prec)
{
	int		dif;
	int		prec_increment;
	int		zero_i;

	dif = 0;
	prec_increment = count_size_fnum(l_num->dec.l_num[index]);
	zero_i = count_sci_exp_zero_i(buf_s, l_num, index, *count_prec);
	if (zero_i == 9)
		prec_increment = 0;
	*count_prec += prec_increment;
	dif = B_AR_CUR.prec - *count_prec;
	if (dif < 0)
	{
		dif = -dif;
		while (dif--)
			l_num->dec.l_num[index] /= 10;
	}
	return (prec_increment);
}

ULL			get_firstdig_sciform(t_buf_struct *buf_s, t_long_num *l_num)
{
	ULL		first_dig;
	int		n_size;

	first_dig = 0;
	n_size = count_size_fnum(l_num->l_num[l_num->filled - 1]);
	if (l_num->filled > 0)
	{
		first_dig = (l_num->l_num[l_num->filled - 1] % ft_pow(10, n_size)
		- l_num->l_num[l_num->filled - 1] % ft_pow(10,
				n_size - 1)) / ft_pow(10, n_size - 1);
		l_num->l_num[l_num->filled - 1] -= first_dig * ft_pow(10, n_size - 1);
		if ((count_size_fnum(l_num->l_num[l_num->filled - 1]) < n_size - 1) ||
		l_num->l_num[l_num->filled - 1] == 0)
		{
			B_AR_CUR.ld_zeros_cut_cell = n_size - 1 -
					((l_num->l_num[l_num->filled - 1] > 0) ?
					(count_size_fnum(l_num->l_num[l_num->filled - 1])) : (0));
			if (l_num->l_num[l_num->filled - 1] == 0)
				if (--(l_num->filled) > 0)
					B_AR_CUR.sci_f_minus_cell = 1;
		}
	}
	return (first_dig);
}

void		cut_exp_num(t_dec_frac *l_num)
{
	ULL		sub;
	ULL		div;
	int		num_length;

	if (l_num->dec.filled > 0)
	{
		num_length = ull_length(l_num->dec.l_num[l_num->dec.filled - 1]);
		div = ft_pow(10, num_length - 1);
		sub = l_num->dec.l_num[l_num->dec.filled - 1] / div;
		l_num->dec.l_num[l_num->dec.filled - 1] -= (sub * div);
	}
	else if (l_num->frac.filled > 0)
	{
		num_length = ull_length(l_num->frac.l_num[l_num->frac.filled - 1]);
		div = ft_pow(10, num_length - 1);
		sub = l_num->frac.l_num[l_num->frac.filled - 1] / div;
		l_num->frac.l_num[l_num->frac.filled - 1] -= (sub * div);
	}
}

int			find_non_zero_char(U_CHAR *tmp)
{
	size_t	i;

	i = 0;
	while (*(tmp + i) == '0')
		++i;
	return (*(tmp + i) - '0');
}
