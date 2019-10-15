/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 21:01:54 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:52:57 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	read_str(U_CHAR **format_str, t_buf_struct *buf_s)
{
	while (**format_str != '%' && **format_str)
		char_to_buf(buf_s, *(*format_str)++);
	*(buf_s->buf + buf_s->size) = 0;
}

void	fill_type_shift(U_CHAR **str)
{
	U_CHAR			*ar;
	U_CHAR			*tmp;

	ar = (U_CHAR*)"#hlLzjt";
	tmp = *str;
	if (**str == '%')
	{
		++(*str);
		while ((**str >= '0' && **str <= '9') || **str == '$' || **str == '*'
		|| **str == '-' || **str == '+' || **str == ' ' || **str == '.' ||
		**str == '#')
			++(*str);
		while (*ar)
		{
			if (*ar == **str)
				++(*str);
			else
				++ar;
		}
	}
}

int		form_str_from_arg(t_buf_struct *buf_s, U_CHAR **format)
{
	int				res;

	res = 0;
	fill_type_shift(format);
	if (**format != '\0')
		++(*format);
	if (buf_s->ar_current + 1 > buf_s->arg_num)
		return (1);
	if (B_AR_CUR.type == 'd' || B_AR_CUR.type == 'D' || B_AR_CUR.type == 'i' ||
	B_AR_CUR.type == 'f' || B_AR_CUR.type == 'F' || B_AR_CUR.type == 'e'
	|| B_AR_CUR.type == 'E' || B_AR_CUR.type == 'g' || B_AR_CUR.type == 'G')
		res = process_signed_num(buf_s);
	else if (B_AR_CUR.type == 'c' || B_AR_CUR.type == 'C' ||
	B_AR_CUR.type == 's' ||
	B_AR_CUR.type == 'S' || B_AR_CUR.type == '%')
		res = process_char(buf_s);
	else if (B_AR_CUR.type == 'u' || B_AR_CUR.type == 'U' ||
	B_AR_CUR.type == 'p' ||
	B_AR_CUR.type == 'o' || B_AR_CUR.type == 'O' || B_AR_CUR.type == 'x' ||
	B_AR_CUR.type == 'X')
		process_unsigned_num(buf_s);
	return (res);
}
