/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_buf_ld_sci_form.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:42:09 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:53:29 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		put_zero_exp(t_buf_struct *buf_s)
{
	char_to_buf(buf_s, '0');
	if (B_AR_CUR.prec || B_AR_CUR.HASH_FLAG)
		char_to_buf(buf_s, '.');
	put_d_zeros(buf_s, B_AR_CUR.prec);
	char_to_buf(buf_s, B_AR_CUR.type == 'e' ? ('e') : ('E'));
	char_to_buf(buf_s, '+');
	put_d_zeros(buf_s, 2);
}

void		put_ldouble_exp(t_buf_struct *buf_s, t_dec_frac *l_num)
{
	if (!(l_num->dec.filled) & !(l_num->frac.filled))
	{
		put_zero_exp(buf_s);
		return ;
	}
	ft_ltoa_base(buf_s, get_firstdig_sciform(buf_s, (l_num->dec.filled > 0)
	? &(l_num->dec) : &(l_num->frac)), 10);
	if (B_AR_CUR.prec || B_AR_CUR.HASH_FLAG)
		char_to_buf(buf_s, '.');
	put_sci_exp_prec(buf_s, l_num);
	char_to_buf(buf_s, B_AR_CUR.type == 'e' ? ('e') : ('E'));
	if (B_AR_CUR.exp_negative == 0)
		char_to_buf(buf_s, '+');
	else if (B_AR_CUR.exp_negative == 1)
		char_to_buf(buf_s, '-');
	if (count_size_fnum(B_AR_CUR.exp_pow) < 2)
		char_to_buf(buf_s, '0');
	ft_ltoa_base(buf_s, B_AR_CUR.exp_pow, 10);
}

void		put_sci_exp_prec(t_buf_struct *buf_s, t_dec_frac *l_num)
{
	int	i;
	int	count_prec;

	i = (*l_num).dec.filled - 1;
	count_prec = 0;
	while (B_AR_CUR.ld_zeros_cut_cell-- > 0 && B_AR_CUR.prec > 0)
	{
		char_to_buf(buf_s, '0');
		--B_AR_CUR.prec;
	}
	if (i >= 0)
	{
		i = put_sci_whole_dec(buf_s, l_num, &count_prec);
		if (i < 0 && count_prec < B_AR_CUR.prec)
		{
			B_AR_CUR.prec -= count_prec;
			make_frac_buf(buf_s, l_num);
		}
		*(buf_s->buf + buf_s->size) = '\0';
	}
	else
		make_frac_buf(buf_s, l_num);
}

int			put_sci_whole_dec(t_buf_struct *buf_s, t_dec_frac *l_num,
		int *count_prec)
{
	int		i;
	int		zero_i;
	int		prec_increment;

	i = l_num->dec.filled - 1;
	zero_i = 0;
	prec_increment = 0;
	while ((i >= 0) & (*count_prec < B_AR_CUR.prec))
	{
		zero_i = count_sci_exp_zero_i(buf_s, l_num, i, *count_prec);
		put_d_zeros(buf_s, zero_i);
		*count_prec += zero_i;
		if (*count_prec == B_AR_CUR.prec)
			break ;
		prec_increment = adjust_sci_exp_lnum_cell(buf_s, l_num, i, count_prec);
		if (prec_increment > 0)
			ft_ltoa_base(buf_s, l_num->dec.l_num[i], 10);
		--i;
	}
	return (i);
}
