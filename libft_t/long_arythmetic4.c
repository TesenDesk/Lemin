/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arythmetic4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:58:07 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:52:44 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** void		make_l_d_dec(t_float_part *p_n, t_dec_frac *l_num)
** {
** 	int		resExp;
** 	int		substractor;
** 	int 	shift;
** 	int		first_pow;
**
** 	resExp = 0;
** 	substractor = 0;
** 	first_pow = 1;
** 	l_num->l_unit.l_num[0] = 2;
** 	l_num->l_unit.filled = 1;
**
** 	с 31 по 37 можно выделить в отдельную функцию
**
**     makeLDDec2(p_n, &shift, &resExp);
** //	if (p_n->exp_part < 64)
** //		shift = p_n->exp_part;
** //	else
** //	{
** //		shift = 63;
** //		resExp = p_n->exp_part - 63;
** //	}
** 	while (resExp <= p_n->exp_part)
** 	{
** 		if ((p_n->frac_part & (1UL << (63 - shift))) != 0)
** 		{
**
** 			с 45 по 55 можно выделить в отдельную функцию
**
**             makeLDDec3(&first_pow, l_num, &resExp, &substractor);
** //			if (first_pow == 1)
** //			{
** //				first_pow = 0;
** //				long_pow(&((*l_num).l_unit), resExp);
** //			}
** //			else
** //			{
** //				int dif = resExp - substractor;
** //				while (dif-- > 0)
** //					long_short_mul(&(l_num->l_unit), (ULL)2);
** //			}
** 			long_add(&((*l_num).dec), &((*l_num).l_unit));
** 			substractor = resExp;
** 		}
** 		++resExp;
** 		--(p_n->frac_length);
** 		--shift;
** 	}
** 	p_n->frac_part <<= resExp;
** 	p_n->exp_part -= resExp;
** 	if ((l_num->dec.l_num[0]))
** 		;
** 	else if (l_num->dec.filled == 1)
** 		l_num->dec.filled = 0;
** }
**
** size_t		make_l_d_frac(t_float_part *p_n, t_dec_frac *l_num)
** {
** 	int		ten_power;
** 	int		temp_pow;
** 	t_long_num tmp_l_num;
** 	int 	substractor;
**
** 	ten_power = p_n->frac_length - 1;
** 	temp_pow = 0;
** 	ULL count_gap = p_n->frac_part;
** 	int i = 0;
** 	tmp_l_num.filled = 1;
** 	tmp_l_num.l_num[0] = 5;
** 	substractor = 0;
** 	p_n->exp_part = -p_n->exp_part;
** 	// long_num_zero(l_num->l_unit.l_num, 1300);
** 	long_num_zero(tmp_l_num.l_num, 1300);
** 	tmp_l_num.filled = 1;
** 	tmp_l_num.l_num[0] = 5;
** 	while (!(count_gap & (1UL << 63)))
** 	{
** 		++i;
** 		count_gap <<= 1;
** 	}
** 	ten_power += i;
** 	int		first_pow = 1;
** 	while (p_n->frac_part != 0)
** 	{
** 		if ((p_n->frac_part & (1UL << 63)))
** 		{
** 			if (first_pow == 1)
** 			{
** 				first_pow = 0;
** 				long_pow(&(tmp_l_num), p_n->exp_part);
** 			}
** 			else
** 			{
** 				int dif = p_n->exp_part - substractor;
** 				while (dif-- > 0)
** 					long_short_mul(&(tmp_l_num), (ULL)5);
** 			}
** 			substractor = p_n->exp_part;
**
** 			long_copy(&(l_num->l_unit), tmp_l_num.l_num, tmp_l_num.filled);
** 			temp_pow = ten_power;
** 			while(temp_pow-- > 0)
** 				long_short_mul(&((*l_num).l_unit), (ULL)10);
** 			long_add(&((*l_num).frac), &((*l_num).l_unit));
** 			long_zero(&((*l_num).l_unit));
** 			(*l_num).l_unit.filled = 0;
** 		}
** 		p_n->frac_part <<= 1;
** 		--ten_power;
** 		++p_n->exp_part;
** 	}
** 	p_n->exp_part = -p_n->exp_part;
** 	if ((l_num->frac.filled == 1) & (!(l_num->frac.l_num[0])))
** 		l_num->frac.filled = 0;
** 	return ((int)(p_n->frac_length - 1) > 0) ? (p_n->frac_length - 1) : (0);
** }
*/

void		count_frac_part_lnum(t_dec_frac *l_num,
		t_float_part *p_n, int ten_power)
{
	int		temp_pow;
	ULL		ten;

	temp_pow = 0;
	ten = 10;
	while (p_n->frac_part)
	{
		if ((p_n->frac_part & (1UL << 63)))
		{
			long_pow(&(l_num->l_unit), p_n->exp_part);
			temp_pow = ten_power;
			while (temp_pow-- > 0)
				long_short_mul(&(l_num->l_unit), ten);
			long_add(&(l_num->frac), &(l_num->l_unit));
			long_zero(&(l_num->l_unit));
			l_num->l_unit.filled = 0;
		}
		p_n->frac_part <<= 1;
		--ten_power;
		--(p_n->exp_part);
	}
}

void		prec_cut_and_put_lnum(t_buf_struct *buf_s, ULL l_num,
		int *count_prec, int zero_i)
{
	int		prec_increment;
	int		dif;

	dif = 0;
	prec_increment = count_size_fnum(l_num);
	if (zero_i == 9)
		prec_increment = 0;
	*count_prec += prec_increment;
	dif = B_AR_CUR.prec - *count_prec;
	if (dif < 0)
	{
		dif = -dif;
		while (dif--)
			l_num /= 10;
	}
	if (prec_increment > 0)
		ft_ltoa_base(buf_s, l_num, 10);
}

int			count_zero_i(t_buf_struct *buf_s, t_dec_frac *l_num,
int count_prec, int index)
{
	int		res;

	res = (index < (int)(l_num->frac.filled - 1) ||
			B_AR_CUR.sci_f_minus_cell == 1) ?
	(9 - count_size_fnum(l_num->frac.l_num[index])) : (0);
	if (l_num->frac.l_num[index] == 0)
		res = 9;
	if (count_prec + res > B_AR_CUR.prec)
		res = 9 - (count_prec + res - B_AR_CUR.prec);
	return (res);
}

void		put_d_zeros(t_buf_struct *buf_s, int zero_i)
{
	while (zero_i-- > 0)
	{
		if (buf_s->size < BUF_SIZE - 1)
			;
		else
			print_and_clear(buf_s);
		*(buf_s->buf + (buf_s->size)++) = '0';
	}
}
