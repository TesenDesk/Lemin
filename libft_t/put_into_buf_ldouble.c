/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_into_buf_ldouble.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:19:32 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:53:47 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		put_zero_ld(t_buf_struct *buf_s)
{
	int				i;
	int				prec;

	i = 0;
	prec = (B_AR_CUR.ld_zeros > B_AR_CUR.prec)
	? (B_AR_CUR.prec) : (B_AR_CUR.ld_zeros);
	while (i < prec)
	{
		if (buf_s->size < BUF_SIZE - 1)
			;
		else
			print_and_clear(buf_s);
		*(buf_s->buf + buf_s->size++) = '0';
		--B_AR_CUR.ld_zeros;
		++i;
	}
	B_AR_CUR.prec -= i;
}

void		put_ldouble(t_buf_struct *buf_s, t_dec_frac *l_num,
		t_fptr_floatoperation operation)
{
	if (B_AR_CUR.MINUS_FLAG)
		B_AR_CUR.ZERO_FLAG = 0;
	if (!(B_AR_CUR.MINUS_FLAG) && !(B_AR_CUR.ZERO_FLAG))
	{
		put_zero_spaces(buf_s, ' ');
		put_sign_or_space(buf_s);
		operation(buf_s, l_num);
	}
	else if (!(B_AR_CUR.MINUS_FLAG) && B_AR_CUR.ZERO_FLAG)
	{
		put_sign_or_space(buf_s);
		put_zero_spaces(buf_s, '0');
		operation(buf_s, l_num);
	}
	else if (B_AR_CUR.MINUS_FLAG)
	{
		put_sign_or_space(buf_s);
		operation(buf_s, l_num);
		put_zero_spaces(buf_s, ' ');
	}
}

void		put_ldouble_num(t_buf_struct *buf_s, t_dec_frac *l_num)
{
	make_dec_buf(buf_s, l_num);
	if (B_AR_CUR.prec || B_AR_CUR.HASH_FLAG)
		char_to_buf(buf_s, '.');
	make_frac_buf(buf_s, l_num);
}
