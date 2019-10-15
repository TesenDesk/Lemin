/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_content2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:01:11 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:50:28 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	chose_char_no_assign(t_arg_opt *opt, size_t arg_pos, va_list *ap)
{
	if (OP_P_TYPE == 'c' && !(OP_P_MOD))
		va_arg(*ap, LL);
	else if ((OP_P_TYPE == 'c' && OP_P_MOD == MOD_D_L) || OP_P_TYPE == 'C')
		va_arg(*ap, int);
	else if (OP_P_TYPE == 's' && !(OP_P_MOD))
		va_arg(*ap, char*);
	else if (OP_P_TYPE == 'S' || (OP_P_TYPE == 's' && OP_P_MOD == MOD_D_L))
		va_arg(*ap, int*);
	else if (OP_P_TYPE == '%')
		;
}
