/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_into_buf_func1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:44:52 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:53:35 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_zero_spaces(t_buf_struct *buf_s, U_CHAR ch)
{
	int				width;

	width = B_AR_CUR.width;
	if (width > 0)
		while (width--)
			char_to_buf(buf_s, ch);
	*(buf_s->buf + buf_s->size) = 0;
}

void	put_dec_sign(t_buf_struct *buf_s)
{
	if (buf_s->arg_ar[buf_s->ar_current].PLUS_FLAG)
		if (B_AR_CUR.sign == 0)
			char_to_buf(buf_s, '+');
	if (B_AR_CUR.sign > 0)
		char_to_buf(buf_s, '-');
}

void	put_sign_or_space(t_buf_struct *buf_s)
{
	if (B_AR_CUR.PLUS_FLAG > 0 || B_AR_CUR.sign > 0)
		char_to_buf(buf_s, B_AR_CUR.sign ? ('-') : ('+'));
	else if (B_AR_CUR.SPACE_FLAG)
		char_to_buf(buf_s, ' ');
	B_AR_CUR.SPACE_FLAG &= 0;
}

void	put_prec(t_buf_struct *buf_s, U_CHAR ch)
{
	if ((B_AR_CUR.type == 's') & (B_AR_CUR.width <= 0))
		return ;
	while (B_AR_CUR.prec-- > 0)
		char_to_buf(buf_s, ch);
	*(buf_s->buf + buf_s->size) = 0;
}

void	put_ox(t_buf_struct *buf_s)
{
	if ((B_AR_CUR.type == 'o' || B_AR_CUR.type == 'O') &&
	B_AR_CUR.HASH_FLAG > 0)
		char_to_buf(buf_s, '0');
	else if ((B_AR_CUR.type == 'x' || B_AR_CUR.type == 'X') &&
	B_AR_CUR.HASH_FLAG > 0)
	{
		if (B_AR_CUR.l_num != 0)
		{
			char_to_buf(buf_s, '0');
			char_to_buf(buf_s, B_AR_CUR.type == 'x' ? ('x') : ('X'));
		}
	}
	else if (B_AR_CUR.type == 'p')
	{
		char_to_buf(buf_s, '0');
		char_to_buf(buf_s, ('x'));
	}
}
