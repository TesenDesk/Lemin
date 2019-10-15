/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arythmetic1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:46:12 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:52:21 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**p_c-place_counter
*/

void		initdec_frac(t_dec_frac *l_num)
{
	size_t		ar_size;

	ar_size = L_AR_SIZE;
	(*l_num).dec.filled = 1;
	(*l_num).frac.filled = 1;
	(*l_num).l_pow.filled = 0;
	(*l_num).l_unit.filled = 0;
	long_num_zero((*l_num).dec.l_num, ar_size);
	long_num_zero((*l_num).frac.l_num, ar_size);
	long_num_zero((*l_num).l_pow.l_num, ar_size);
	long_num_zero((*l_num).l_unit.l_num, ar_size);
}

void		count_ld_num(t_buf_struct *buf_s, t_float_part *p_n,
		t_dec_frac *l_num)
{
	make_ld_dec(p_n, l_num);
	if ((*p_n).frac_part)
	{
		buf_s->arg_ar[buf_s->ar_current].ld_zeros += -p_n->exp_part;
		buf_s->arg_ar[buf_s->ar_current].ld_zeros += count_gap(p_n->frac_part) +
				p_n->frac_length - 1;
		make_ld_frac(p_n, l_num);
		buf_s->arg_ar[buf_s->ar_current].ld_zeros -= count_size_fnum(l_num->
				frac.l_num[l_num->frac.filled - 1]);
		buf_s->arg_ar[buf_s->ar_current].ld_zeros -=
				(l_num->frac.filled - 1) * 9;
	}
	else
		l_num->frac.filled &= 0;
}

/*
** i внутри!
*/

size_t		count_gap(ULL frac_part)
{
	size_t i;

	i = 0;
	while (!(((ULL)1 << 63) & frac_part) & (i < 63))
	{
		frac_part <<= 1;
		i++;
	}
	return (i);
}
