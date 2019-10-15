/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:26:41 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:53:15 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		process_unsigned_num(t_buf_struct *buf_s)
{
	U_CHAR			base;

	base = 10;
	if (B_AR_CUR.type == 'o' || B_AR_CUR.type == 'O')
		base = 8;
	else if (B_AR_CUR.type == 'x' || B_AR_CUR.type == 'X' ||
	B_AR_CUR.type == 'p')
		base = 16;
	if ((B_AR_CUR.HASH_FLAG) || B_AR_CUR.prec != 0)
	{
		B_AR_CUR.SPACE_FLAG &= 0;
		if (B_AR_CUR.prec != 0)
			B_AR_CUR.ZERO_FLAG &= 0;
	}
	manage_unsigned_num(buf_s, base);
}

void		manage_dec_num(t_buf_struct *buf_s, U_CHAR base)
{
	adjust_num_width(buf_s);
	if (B_AR_CUR.prec != 0)
		B_AR_CUR.ZERO_FLAG &= 0;
	if (!(B_AR_CUR.MINUS_FLAG) &&
	!(B_AR_CUR.ZERO_FLAG))
	{
		put_zero_spaces(buf_s, ' ');
		put_sign_or_space(buf_s);
		put_dec_num(buf_s, base);
	}
	else if (!(B_AR_CUR.MINUS_FLAG) &&
	B_AR_CUR.ZERO_FLAG)
	{
		put_sign_or_space(buf_s);
		put_zero_spaces(buf_s, '0');
		put_dec_num(buf_s, base);
	}
	else if (B_AR_CUR.MINUS_FLAG)
	{
		put_sign_or_space(buf_s);
		put_dec_num(buf_s, base);
		put_zero_spaces(buf_s, ' ');
	}
}

int			process_signed_num(t_buf_struct *buf_s)
{
	U_CHAR			base;

	base = 10;
	if (B_AR_CUR.type == 'd' || B_AR_CUR.type == 'D' || B_AR_CUR.type == 'i')
		manage_dec_num(buf_s, base);
	if (B_AR_CUR.type == 'f' || B_AR_CUR.type == 'F'
	|| B_AR_CUR.type == 'e' || B_AR_CUR.type == 'E' || B_AR_CUR.type == 'g'
	|| B_AR_CUR.type == 'G')
		manage_ldouble_num(buf_s);
	return (1);
}

void		manage_unsigned_num(t_buf_struct *buf_s, U_CHAR base)
{
	B_AR_CUR.PLUS_FLAG = 0;
	B_AR_CUR.SPACE_FLAG = 0;
	if ((B_AR_CUR.type == 'o' || B_AR_CUR.type == 'O')
	&& B_AR_CUR.HASH_FLAG > 0)
		B_AR_CUR.prec -= ((B_AR_CUR.prec > 1) ? (1) : (2));
	adjust_num_width(buf_s);
	if (!(B_AR_CUR.MINUS_FLAG) && !(B_AR_CUR.ZERO_FLAG))
	{
		put_zero_spaces(buf_s, ' ');
		put_ox(buf_s);
		put_dec_num(buf_s, base);
	}
	else if (!(B_AR_CUR.MINUS_FLAG) && B_AR_CUR.ZERO_FLAG)
	{
		put_ox(buf_s);
		put_zero_spaces(buf_s, '0');
		put_dec_num(buf_s, base);
	}
	else if (B_AR_CUR.MINUS_FLAG)
	{
		put_ox(buf_s);
		put_dec_num(buf_s, base);
		put_zero_spaces(buf_s, ' ');
	}
}
