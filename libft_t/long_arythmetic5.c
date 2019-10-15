/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arythmetic5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:06:00 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:52:50 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		make_ld_dec(t_float_part *p_n, t_dec_frac *l_num)
{
	int		res_exp;
	int		p_c;

	res_exp = 0;
	p_c = 0;
	while (p_n->frac_part && (res_exp = (p_n->exp_part - p_c)) >= 0)
	{
		if ((p_n->frac_part & (1UL << 63)) != 0)
		{
			if (res_exp >= 0)
				long_add(&((*l_num).dec), long_pow(&((*l_num).l_unit),
						res_exp));
			long_zero(&((*l_num).l_unit));
			(*l_num).l_unit.filled = 0;
		}
		p_n->frac_part <<= 1;
		--(p_n->frac_length);
		++p_c;
	}
	p_n->exp_part -= p_c;
	if ((l_num->dec.l_num[0]))
		;
	else if (l_num->dec.filled == 1)
		l_num->dec.filled = 0;
}

size_t		make_ld_frac(t_float_part *p_n, t_dec_frac *l_num)
{
	int			ten_power;
	int			temp_pow;
	t_long_num	tmp_l_num;
	int			i;
	ULL			count_gap;

	ten_power = p_n->frac_length - 1;
	temp_pow = 0;
	count_gap = p_n->frac_part;
	i = 0;
	tmp_l_num.filled = 1;
	tmp_l_num.l_num[0] = 1;
	while (!(count_gap & (1UL << 63)))
	{
		++i;
		count_gap <<= 1;
	}
	ten_power += i;
	count_frac_part_lnum(l_num, p_n, ten_power);
	if ((l_num->frac.filled == 1) & (!(l_num->frac.l_num[0])))
		l_num->frac.filled = 0;
	return ((int)(p_n->frac_length - 1) > 0) ? (p_n->frac_length - 1) : (0);
}

int			make_dec_buf(t_buf_struct *buf_s, t_dec_frac *l_num)
{
	int				i;
	size_t			zero_i;

	i = (*l_num).dec.filled - 1;
	if (i < 0)
	{
		if (buf_s->size < BUF_SIZE - 1)
			*(buf_s->buf + (buf_s->size)++) = '0';
		else
		{
			print_and_clear(buf_s);
			*(buf_s->buf + (buf_s->size)++) = '0';
		}
	}
	while (i >= 0)
	{
		zero_i = count_size_fnum(l_num->dec.l_num[i]);
		if (i < (int)((*l_num).dec.filled - 1))
			put_d_zeros(buf_s, 9 - zero_i);
		ft_ltoa_base(buf_s, l_num->dec.l_num[i], 10);
		--i;
	}
	return (1);
}

void		make_frac_buf(t_buf_struct *buf_s, t_dec_frac *l_num)
{
	int				i;
	int				zero_i;
	int				c_prec;

	c_prec = 0;
	i = (*l_num).frac.filled - 1;
	zero_i = 0;
	if (i < 0)
	{
		put_d_zeros(buf_s, (size_t)buf_s->arg_ar[buf_s->ar_current].prec);
		return ;
	}
	put_zero_ld(buf_s);
	while ((i >= 0) & (c_prec < B_AR_CUR.prec))
	{
		zero_i = count_zero_i(buf_s, l_num, c_prec, i);
		put_d_zeros(buf_s, zero_i);
		c_prec += zero_i;
		if (c_prec == B_AR_CUR.prec)
			break ;
		prec_cut_and_put_lnum(buf_s, l_num->frac.l_num[i--], &c_prec, zero_i);
	}
	if (c_prec < B_AR_CUR.prec)
		put_d_zeros(buf_s, B_AR_CUR.prec - c_prec);
}
