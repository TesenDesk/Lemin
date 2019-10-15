/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:30:51 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:50:20 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	chose_signed_dec(t_arg_opt *opt, size_t arg_pos, va_list *ap)
{
	if (is_signed_int(OP_P_TYPE) && !(OP_P_MOD))
		(OP_P_LNM) = (int)va_arg(*ap, LL);
	else if (OP_P_MOD == MOD_D_H)
		(OP_P_LNM) = (short)va_arg(*ap, LL);
	else if (OP_P_MOD == MOD_D_HH)
		(OP_P_LNM) = (char)va_arg(*ap, LL);
	else if (OP_P_MOD == MOD_D_L)
		(OP_P_LNM) = (long)va_arg(*ap, LL);
	else if (OP_P_MOD == MOD_D_LL)
		(OP_P_LNM) = va_arg(*ap, LL);
	else if (OP_P_MOD == MOD_D_J)
		(OP_P_LNM) = va_arg(*ap, intmax_t);
	else if (OP_P_MOD == MOD_D_Z)
		(OP_P_LNM) = (size_t)va_arg(*ap, LL);
}

void	chose_unsigned_dec(t_arg_opt *opt, size_t arg_pos, va_list *ap)
{
	if (is_unsigned(OP_P_TYPE) && !(OP_P_MOD))
		(OP_P_LNM) = (unsigned int)va_arg(*ap, LL);
	else if (OP_P_MOD == MOD_D_Z)
		(OP_P_LNM) = (size_t)va_arg(*ap, LL);
	else if (OP_P_MOD == MOD_D_J)
		(OP_P_LNM) = va_arg(*ap, uintmax_t);
	else if (OP_P_MOD == MOD_D_H)
		(OP_P_LNM) = (unsigned short)va_arg(*ap, LL);
	else if (OP_P_MOD == MOD_D_HH)
		(OP_P_LNM) = (unsigned char)va_arg(*ap, LL);
	else if (OP_P_MOD == MOD_D_L)
		(OP_P_LNM) = (unsigned long)va_arg(*ap, LL);
	else if (OP_P_MOD == MOD_D_LL)
		(OP_P_LNM) = (ULL)va_arg(*ap, LL);
}

void	chose_floating_point(t_arg_opt *opt, size_t arg_pos, va_list *ap)
{
	if ((OP_P_TYPE == 'e' || OP_P_TYPE == 'E' || OP_P_TYPE == 'f'
	|| OP_P_TYPE == 'F'
	|| OP_P_TYPE == 'g' || OP_P_TYPE == 'G') && (OP_P_MOD == MOD_D_L
	|| !(OP_P_MOD)))
		(OP_P_LDN) = (LD)va_arg(*ap, double);
	else if ((OP_P_TYPE == 'e' || OP_P_TYPE == 'E' || OP_P_TYPE == 'f' ||
	OP_P_TYPE == 'F' || OP_P_TYPE == 'g' || OP_P_TYPE == 'G')
	&& OP_P_MOD == MOD_F_L)
		(OP_P_LDN) = va_arg(*ap, LD);
}

void	chose_char(t_arg_opt *opt, size_t arg_pos, va_list *ap)
{
	if (OP_P_TYPE == 'c' && !(OP_P_MOD))
		(OP_P_LNM) = (U_CHAR)va_arg(*ap, LL);
	else if ((OP_P_TYPE == 'c' && OP_P_MOD == MOD_D_L) || OP_P_TYPE == 'C')
		(OP_P_LNM) = va_arg(*ap, int);
	else if (OP_P_TYPE == 's' && !(OP_P_MOD))
		opt[arg_pos].str = (U_CHAR*)va_arg(*ap, char*);
	else if (OP_P_TYPE == 'S' || (OP_P_TYPE == 's' && OP_P_MOD == MOD_D_L))
		opt[arg_pos].utf_str = va_arg(*ap, int*);
	else if (OP_P_TYPE == '%')
		opt[arg_pos].l_num = OP_P_TYPE;
}

void	chose_ptr(t_arg_opt *opt, size_t arg_pos, va_list *ap)
{
	opt[arg_pos].l_num = (LL)(va_arg((*ap), unsigned int*));
}
