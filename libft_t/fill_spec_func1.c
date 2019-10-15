/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spec_func1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:09:47 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:51:07 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		fill_content(t_arg_opt *opt, size_t arg_pos, va_list *ap_origin)
{
	int					index;
	int					index2;
	va_list				ap;

	index = 0;
	index2 = 0;
	if (!(opt[index].param_active))
		chose_content(opt, arg_pos, ap_origin);
	else
	{
		va_copy(ap, *ap_origin);
		skip_args(opt, arg_pos, &ap);
		chose_content(opt, arg_pos, &ap);
	}
}

void		skip_args(t_arg_opt *opt, size_t arg_pos, va_list *ap)
{
	size_t	index;
	size_t	index2;

	index = 0;
	index2 = 0;
	while (index < (size_t)(opt[arg_pos].param_num - 1))
	{
		index2 = 0;
		while (opt[index2].param_num - 1 != (int)index)
			index2++;
		chose_char_no_assign(opt, index, ap);
		++index;
	}
}

void		fill_type(U_CHAR *str, t_arg_opt *opt, size_t arg_pos)
{
	U_CHAR	*ar;

	ar = (U_CHAR*)"#hlLzjt";
	while ((*str >= '0' && *str <= '9') || *str == '$' || *str == '*'
	|| *str == '-' || *str == '+' || *str == ' ' || *str == '.' || *str == '#')
		++str;
	while (*ar)
	{
		if (*ar == *str)
			++str;
		else
			++ar;
	}
	OP_P_TYPE = *str;
}

size_t		fill_params(U_CHAR **str, t_arg_opt *opt, size_t arg_pos)
{
	U_CHAR	*tmp;
	size_t	tmp_pos;

	tmp = *str;
	while (**str <= '9' && **str >= '0')
		++(*str);
	if (**str != '$')
	{
		opt[arg_pos].param_active = 0;
		opt[arg_pos].param_num = 0;
		*str = tmp;
		return (0);
	}
	else
	{
		++(*str);
		tmp_pos = (size_t)(ft_atol(tmp));
		opt[arg_pos].param_active = 1;
		opt[arg_pos].param_num = tmp_pos;
		return (tmp_pos);
	}
}

void		fill_flags(U_CHAR **str, t_arg_opt *opt, size_t arg_pos)
{
	while (**str && **str < '1' && **str != '.' && **str != '%' && **str != '*')
	{
		if (**str == '0')
			opt[arg_pos].ZERO_FLAG = 1;
		if (**str == '-')
			opt[arg_pos].MINUS_FLAG = 1;
		if (**str == '+')
			opt[arg_pos].PLUS_FLAG = 1;
		if (**str == ' ')
			opt[arg_pos].SPACE_FLAG = 1;
		if (**str == '#')
			opt[arg_pos].HASH_FLAG = 1;
		++(*str);
	}
	if (opt[arg_pos].PLUS_FLAG || opt[arg_pos].type == 'c')
		opt[arg_pos].SPACE_FLAG &= 0;
	if (opt[arg_pos].MINUS_FLAG)
		opt[arg_pos].ZERO_FLAG &= 0;
	if (opt[arg_pos].type == 'c')
	{
		opt[arg_pos].PLUS_FLAG &= 0;
		opt[arg_pos].HASH_FLAG &= 0;
	}
}
