/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spec_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:59:33 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:51:13 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				fill_mod(U_CHAR **format_str, t_arg_opt *opt, size_t pos)
{
	U_CHAR *str;

	str = (U_CHAR*)"hlLzj";
	while (*str++)
		if (**format_str == *(str - 1))
		{
			if (*(str - 1) == 'h' && *((*format_str) + 1) != 'h')
				opt[pos].mod = MOD_D_H;
			else if (*(str - 1) == 'h' && *((*format_str) + 1) == 'h')
				opt[pos].mod = MOD_D_HH;
			else if (*(str - 1) == 'l' && *((*format_str) + 1) != 'l')
				opt[pos].mod = MOD_D_L;
			else if (*(str - 1) == 'l' && *((*format_str) + 1) == 'l')
				opt[pos].mod = MOD_D_LL;
			else if (*(str - 1) == 'z')
				opt[pos].mod = MOD_D_Z;
			else if (*(str - 1) == 'j')
				opt[pos].mod = MOD_D_J;
			else if (*(str - 1) == 'L')
				opt[pos].mod = MOD_F_L;
			else if (*(str - 1) == 't')
				opt[pos].mod = MOD_T;
			++(*format_str);
			return ;
		}
}

void				fill_width(U_CHAR **str, t_arg_opt *opt, size_t pos,
		va_list *ap)
{
	if (**str == '*')
	{
		opt[pos].width = va_arg(*ap, int);
		++(*str);
		if (opt[pos].width < 0)
		{
			opt[pos].MINUS_FLAG = 1;
			opt[pos].width = -opt[pos].width;
		}
	}
	else
	{
		opt[pos].width = ft_atol(*str);
		while (**str >= '0' && **str <= '9')
			++(*str);
	}
	if (opt[pos].width < 0)
		opt[pos].width = 0;
}

void				fill_precision(U_CHAR **str, t_arg_opt *opt,
		size_t arg_pos, va_list *ap)
{
	if (!(**str == '.'))
	{
		if (is_floating(opt[arg_pos].type))
			opt[arg_pos].prec = 6;
	}
	else
	{
		++(*str);
		if (**str == '*')
			opt[arg_pos].prec = va_arg(*ap, int);
		else
			opt[arg_pos].prec = ft_atol(*str);
		while (**str >= '0' && **str <= '9')
			++(*str);
		if (opt[arg_pos].prec <= 0 && (is_integer(opt[arg_pos].type)))
			opt[arg_pos].prec = -1;
		else if (opt[arg_pos].prec == 0 && is_string(opt[arg_pos].type))
			opt[arg_pos].prec = -1;
		else if (opt[arg_pos].prec < 0 && is_string(opt[arg_pos].type))
			opt[arg_pos].prec = 0;
		else if (opt[arg_pos].prec < 0 && (is_floating(opt[arg_pos].type)))
			opt[arg_pos].prec = 6;
	}
}

int					check_for_spec(U_CHAR tmp)
{
	if (tmp == 'd' || tmp == 'i' || tmp == 'o' || tmp == 'u'
	|| tmp == 'x' || tmp == 'D' || tmp == 'O' || tmp == 'U'
	|| tmp == 'X' || tmp == 'e' || tmp == 'E' || tmp == 'f'
	|| tmp == 'F' || tmp == 'g' || tmp == 'G' || tmp == 'c'
	|| tmp == 'C' || tmp == 's' || tmp == 'S' || tmp == 'p'
	|| tmp == '%')
		return (1);
	return (0);
}
