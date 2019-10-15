/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_prec_sci_form.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:54:56 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:49:45 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		sci_positive_dec_c_point(t_buf_struct *buf_s,
t_dec_frac *l_num, int *cut_point)
{
	if (B_AR_CUR.prec < (int)count_dec_frac_digs(&(l_num->dec)) - 1 &&
	B_AR_CUR.prec > 0)
		*cut_point = FULL_DEC;
	else if ((B_AR_CUR.prec == (int)count_dec_frac_digs(&(l_num->dec)) - 1) ||
	B_AR_CUR.prec == 0)
		*cut_point = DEC_FRAC_EDGE;
	else if (B_AR_CUR.prec > (int)count_dec_frac_digs(&(l_num->dec)) - 1)
		*cut_point = PART_FRAC;
}

int			sci_c_prec(t_buf_struct *buf_s,
t_dec_frac *l_num, int cut_point)
{
	int c_prec;

	c_prec = 0;
	if (cut_point == FULL_FRAC)
		c_prec = count_size_fnum(l_num->frac.l_num[l_num->frac.filled - 1])
		+ B_AR_CUR.ld_zeros - 1;
	else if (cut_point == PART_FRAC)
		c_prec = count_size_fnum(l_num->frac.l_num[l_num->frac.filled - 1]) +
		B_AR_CUR.ld_zeros;
	else if (cut_point == DEC_FRAC_EDGE)
		c_prec = 0;
	else if (cut_point == FULL_DEC)
		c_prec = count_size_fnum(l_num->dec.l_num[l_num->dec.filled - 1]) -
		1;
	return (c_prec);
}

void		adjust_double_sci_form(t_buf_struct *buf_s,
		t_dec_frac *l_num)
{
	int			cut_point;
	int			c_prec;
	ULL			tmp_num;

	cut_point = 0;
	c_prec = 0;
	tmp_num = 0;
	if (l_num->dec.filled > 0)
		sci_positive_dec_c_point(buf_s, l_num, &cut_point);
	else
	{
		cut_point = FULL_FRAC;
		B_AR_CUR.ld_zeros &= 0;
	}
	c_prec = sci_c_prec(buf_s, l_num, cut_point);
	tmp_num = find_first_dig_sciform(l_num);
	adjust_sci_prec(buf_s, l_num, c_prec, cut_point);
	if (tmp_num != 1 && check_for_ones(find_first_l_num(l_num)))
		B_AR_CUR.exp_pow += 1;
}

ULL			find_first_dig_sciform(t_dec_frac *l_num)
{
	ULL			first_dig;
	int			num_size;

	first_dig = 0;
	if (l_num->dec.filled > 0)
	{
		num_size = count_size_fnum(l_num->dec.l_num[l_num->dec.filled - 1]);
		first_dig = (l_num->dec.l_num[l_num->dec.filled - 1] %
				ft_pow(10, num_size) - l_num->dec.l_num[l_num->dec.filled - 1] %
				ft_pow(10, num_size - 1)) / ft_pow(10,
		num_size - 1);
	}
	else if (l_num->frac.filled > 0)
	{
		num_size = count_size_fnum(l_num->frac.l_num[l_num->frac.filled - 1]);
		first_dig = (l_num->frac.l_num[l_num->frac.filled - 1] %
				ft_pow(10, num_size)
		- l_num->frac.l_num[l_num->frac.filled - 1] % ft_pow(10,
				num_size - 1)) / ft_pow(10, num_size - 1);
	}
	return (first_dig);
}

void		adjust_sci_prec(t_buf_struct *buf_s, t_dec_frac *l_num,
		int c_prec, int cut_point)
{
	if (cut_point == FULL_FRAC)
		adjust_double_norm_form(l_num, B_AR_CUR.prec, c_prec,
				&(B_AR_CUR.ld_zeros));
	else if (cut_point == PART_FRAC)
		adjust_double_norm_form(l_num, B_AR_CUR.prec -
		(count_dec_frac_digs(&(l_num->dec)) - 1), c_prec, &(B_AR_CUR.ld_zeros));
	else if (cut_point == DEC_FRAC_EDGE)
		adjust_double_norm_form(l_num, 0, 0, &(B_AR_CUR.ld_zeros));
	else if (cut_point == FULL_DEC)
	{
		if (c_prec < B_AR_CUR.prec)
		{
			l_num->dec.cur = l_num->dec.filled - 1;
			while (c_prec < B_AR_CUR.prec && --(l_num->dec.cur) >= 0)
				c_prec += 9;
			analize_frac_cell_dec(l_num, c_prec - B_AR_CUR.prec);
		}
		else if (c_prec == B_AR_CUR.prec)
			analize_frac_cell_z_p_0_dec(l_num, l_num->dec.cur);
		else if (c_prec > B_AR_CUR.prec)
			analize_frac_cell_dec(l_num, c_prec - B_AR_CUR.prec);
	}
}
