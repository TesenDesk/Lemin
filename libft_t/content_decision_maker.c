/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_decision_maker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:28:47 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:50:53 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			find_chose_opt_index(char type)
{
	if (is_signed_int(type))
		return (IS_SIGNED_DEC);
	else if (is_unsigned(type))
		return (IS_UNSIGNED_DEC);
	else if (is_floating(type))
		return (IS_FRAC);
	else if (type == 'c' || type == 'C' || type == 's' ||
	type == 'S' || type == '%')
		return (IS_CHAR);
	else if (type == 'p')
		return (IS_PTR);
	return (0);
}

void		chose_content(t_arg_opt *opt, size_t pos, va_list *ap)
{
	int index;

	index = find_chose_opt_index(opt[pos].type);
	if (index == IS_SIGNED_DEC)
		chose_signed_dec(opt, pos, ap);
	if (index == IS_UNSIGNED_DEC)
		chose_unsigned_dec(opt, pos, ap);
	if (index == IS_FRAC)
		chose_floating_point(opt, pos, ap);
	if (index == IS_CHAR)
		chose_char(opt, pos, ap);
	if (index == IS_PTR)
		chose_ptr(opt, pos, ap);
}
