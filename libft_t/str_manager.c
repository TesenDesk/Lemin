/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:53:05 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:54:01 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		count_str_len(t_arg_opt *opt)
{
	int		utf_str_size;
	int		i;

	i = 0;
	utf_str_size = 0;
	if (opt->type == 's' && !(opt->mod))
		return (ft_strlen((const char*)(opt->str)));
	else
	{
		while (opt->utf_str[i])
			utf_str_size += find_utf_len(opt->utf_str[i++]);
	}
	return (utf_str_size);
}

void		adjust_utf_width(t_buf_struct *buf_s)
{
	int	i;
	int	add;

	i = 0;
	add = 0;
	if ((B_AR_CUR.type == 's' && B_AR_CUR.mod == MOD_D_L) ||
	B_AR_CUR.type == 'S')
	{
		if (B_AR_CUR.width >= B_AR_CUR.len || B_AR_CUR.prec > 0)
		{
			while (add < B_AR_CUR.len)
				add += find_utf_len(B_AR_CUR.utf_str[i++]);
			if (add > B_AR_CUR.len)
				add -= find_utf_len(B_AR_CUR.utf_str[i - 1]);
			B_AR_CUR.width -= add;
		}
		else
			B_AR_CUR.width &= 0;
	}
	else
		B_AR_CUR.width -= B_AR_CUR.len;
}

void		manage_str(t_buf_struct *buf_s)
{
	U_CHAR	p;

	if (!(B_AR_CUR.str == NULL) || !(B_AR_CUR.utf_str == NULL))
		B_AR_CUR.len = count_str_len(&B_AR_CUR);
	if (B_AR_CUR.str == NULL && B_AR_CUR.utf_str == NULL)
	{
		B_AR_CUR.str = (U_CHAR*)"(null)\0";
		B_AR_CUR.len = 6;
		B_AR_CUR.type = 's';
		B_AR_CUR.mod &= 0;
	}
	if (B_AR_CUR.prec >= 0)
		B_AR_CUR.len = ((B_AR_CUR.prec <= B_AR_CUR.len) & (B_AR_CUR.prec > 0))
								? (B_AR_CUR.prec) : (B_AR_CUR.len);
	else
		B_AR_CUR.len = 0;
	adjust_utf_width(buf_s);
	p = (B_AR_CUR.ZERO_FLAG > 0) ? '0' : ' ';
	if (!(B_AR_CUR.MINUS_FLAG))
		put_zero_spaces(buf_s, p);
	str_to_buf(buf_s, B_AR_CUR.len);
	if (B_AR_CUR.MINUS_FLAG && B_AR_CUR.width > 0)
		put_zero_spaces(buf_s, ' ');
}

void		str_to_buf(t_buf_struct *buf_s, size_t len)
{
	int	i;
	int addition;
	int j;

	i = 0;
	addition = 0;
	if ((B_AR_CUR.type == 's' && !(B_AR_CUR.mod)) ||
	!(B_AR_CUR.type == 's' || B_AR_CUR.type == 'S'))
		while (i < (int)len)
			char_to_buf(buf_s, B_AR_CUR.str[i++]);
	else
	{
		j = 0;
		while (j < (int)len)
		{
			addition += find_utf_len(B_AR_CUR.utf_str[i]);
			if (addition <= B_AR_CUR.len)
				ft_putchar_utf(buf_s, B_AR_CUR.utf_str[i++]);
			else
				return ;
			++j;
		}
	}
}
