/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:12:15 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:50:14 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			process_char(t_buf_struct *buf_s)
{
	if (B_AR_CUR.type == 'c' || B_AR_CUR.type == '%' || B_AR_CUR.type == 'C')
		manage_char_or_percent(buf_s);
	else if (B_AR_CUR.type == 's' || B_AR_CUR.type == 'S')
		manage_str(buf_s);
	return (1);
}

void		manage_char_or_percent(t_buf_struct *buf_s)
{
	U_CHAR	p;

	p = B_AR_CUR.ZERO_FLAG ? '0' : ' ';
	if (B_AR_CUR.type == '%')
		B_AR_CUR.l_num = '%';
	if ((B_AR_CUR.type == 'c' && B_AR_CUR.mod == MOD_D_L) ||
	B_AR_CUR.type == 'C')
		B_AR_CUR.width -= find_utf_len(B_AR_CUR.l_num);
	else
		--B_AR_CUR.width;
	if (!(B_AR_CUR.MINUS_FLAG) && B_AR_CUR.width > 0)
		put_zero_spaces(buf_s, p);
	if ((B_AR_CUR.type == 'c' && !(B_AR_CUR.mod)) || B_AR_CUR.type == '%')
		char_to_buf(buf_s, (U_CHAR)B_AR_CUR.l_num);
	else
		ft_putchar_utf(buf_s, B_AR_CUR.l_num);
	if (B_AR_CUR.MINUS_FLAG && B_AR_CUR.width > 0)
		put_zero_spaces(buf_s, ' ');
}

void		char_to_buf(t_buf_struct *buf_s, U_CHAR ch)
{
	if (buf_s->size < BUF_SIZE - 1)
		*(buf_s->buf + (buf_s->size)++) = ch;
	else
	{
		print_and_clear(buf_s);
		*(buf_s->buf + (buf_s->size)++) = ch;
	}
}
