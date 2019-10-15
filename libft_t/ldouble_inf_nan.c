/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble_inf_nan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:48:58 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:51:34 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			check_for_inf_nan(t_buf_struct *buf_s, t_float_part *p_n)
{
	ULL			mant;

	mant = p_n->frac_part;
	mant &= 9223372036854775807;
	if (p_n->exp_part == 16384)
	{
		if ((!mant))
			str_to_inf(buf_s);
		else
			str_to_nan(buf_s);
		B_AR_CUR.prec = 3;
		put_inf_nan(buf_s);
		return (1);
	}
	return (0);
}

void		str_to_inf(t_buf_struct *buf_s)
{
	if (B_AR_CUR.type == 'f' || B_AR_CUR.type == 'e' || B_AR_CUR.type == 'g')
		B_AR_CUR.str = (U_CHAR*)"inf";
	else if (B_AR_CUR.type == 'F' || B_AR_CUR.type == 'E' ||
	B_AR_CUR.type == 'G')
		B_AR_CUR.str = (U_CHAR*)"INF";
}

void		str_to_nan(t_buf_struct *buf_s)
{
	if (B_AR_CUR.type == 'f' || B_AR_CUR.type == 'e' || B_AR_CUR.type == 'g')
		B_AR_CUR.str = (U_CHAR*)"nan";
	else if (B_AR_CUR.type == 'F' || B_AR_CUR.type == 'E' ||
	B_AR_CUR.type == 'G')
		B_AR_CUR.str = (U_CHAR*)"NAN";
	B_AR_CUR.SPACE_FLAG &= 0;
	B_AR_CUR.PLUS_FLAG &= 0;
	B_AR_CUR.sign = 0;
}

void		put_inf_nan(t_buf_struct *buf_s)
{
	B_AR_CUR.ZERO_FLAG &= 0;
	B_AR_CUR.width -= B_AR_CUR.prec;
	B_AR_CUR.width -= (B_AR_CUR.sign > 0 || B_AR_CUR.PLUS_FLAG > 0 ||
			B_AR_CUR.SPACE_FLAG > 0) ? (1) : (0);
	if (!(B_AR_CUR.MINUS_FLAG))
	{
		put_zero_spaces(buf_s, ' ');
		put_sign_or_space(buf_s);
		str_to_buf(buf_s, B_AR_CUR.prec);
	}
	else if (B_AR_CUR.MINUS_FLAG)
	{
		put_sign_or_space(buf_s);
		str_to_buf(buf_s, B_AR_CUR.prec);
		put_zero_spaces(buf_s, ' ');
	}
}
