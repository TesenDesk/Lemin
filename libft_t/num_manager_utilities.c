/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_manager_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:52:38 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:53:03 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		put_dec_num(t_buf_struct *buf_s, U_CHAR base)
{
	if (B_AR_CUR.prec >= 0)
	{
		B_AR_CUR.prec -= B_AR_CUR.len;
		put_prec(buf_s, '0');
		ft_ltoa_base(buf_s, B_AR_CUR.l_num, base);
	}
	else if (B_AR_CUR.l_num != 0)
		ft_ltoa_base(buf_s, B_AR_CUR.l_num, base);
}

void		adjust_num_width(t_buf_struct *buf_s)
{
	int		substract;
	size_t	exp_size;

	substract = (B_AR_CUR.PLUS_FLAG > 0 || B_AR_CUR.sign > 0) ? (1) : (0);
	if (B_AR_CUR.type == 'd' || B_AR_CUR.type == 'D' || B_AR_CUR.type == 'i' ||
	B_AR_CUR.type == 'f' || B_AR_CUR.type == 'e')
		substract += B_AR_CUR.SPACE_FLAG ? (1) : (0);
	if (((B_AR_CUR.type == 'x' || B_AR_CUR.type == 'X')
	&& B_AR_CUR.HASH_FLAG > 0 && B_AR_CUR.l_num != 0) ||
	((B_AR_CUR.type == 'o' || B_AR_CUR.type == 'O') && B_AR_CUR.HASH_FLAG > 0)
	|| B_AR_CUR.type == 'p')
		substract += (B_AR_CUR.type == 'o' || B_AR_CUR.type == 'O') ? (1) : (2);
	exp_size = count_size_fnum((ULL)B_AR_CUR.exp_pow);
	if (is_integer(B_AR_CUR.type) > 0)
		adjust_int_width(buf_s, &substract);
	else if (B_AR_CUR.type == 'f')
		B_AR_CUR.width -= (B_AR_CUR.len + substract);
	else if (B_AR_CUR.type == 'e')
	{
		substract += 3 + B_AR_CUR.prec + ((exp_size > 2) ? (exp_size) : (2));
		if (B_AR_CUR.prec > 0 || B_AR_CUR.HASH_FLAG > 0)
			substract += 1;
		B_AR_CUR.width -= substract;
	}
}

void		adjust_int_width(t_buf_struct *buf_s, int *substract)
{
	if (B_AR_CUR.type == 'd' || B_AR_CUR.type == 'D' || B_AR_CUR.type == 'i' ||
	B_AR_CUR.type == 'u' || B_AR_CUR.type == 'U')
		B_AR_CUR.len = count_base(B_AR_CUR.l_num, 10);
	if (B_AR_CUR.type == 'o' || B_AR_CUR.type == 'O')
		B_AR_CUR.len = count_base(B_AR_CUR.l_num, 8);
	if (B_AR_CUR.type == 'x' || B_AR_CUR.type == 'X' || B_AR_CUR.type == 'p')
		B_AR_CUR.len = count_base(B_AR_CUR.l_num, 16);
	if (B_AR_CUR.prec < 0)
	{
		if ((B_AR_CUR.type == 'd' || B_AR_CUR.type == 'D' ||
		B_AR_CUR.type == 'i' || B_AR_CUR.type == 'u' || B_AR_CUR.type == 'U')
		&& B_AR_CUR.l_num != 0)
			*substract += B_AR_CUR.len;
		else if ((B_AR_CUR.type == 'x' || B_AR_CUR.type == 'X' ||
		B_AR_CUR.type == 'o' || B_AR_CUR.type == 'O' || B_AR_CUR.type == 'p') &&
		B_AR_CUR.l_num != 0)
			*substract += B_AR_CUR.len;
	}
	else if (B_AR_CUR.prec >= 0)
		*substract += (B_AR_CUR.len >= B_AR_CUR.prec)
						? (B_AR_CUR.len) : (B_AR_CUR.prec);
	B_AR_CUR.width -= *substract;
}

int			count_size_dec_num(LL num, int base)
{
	short			size;

	size = 0;
	while (num)
	{
		++size;
		num /= base;
	}
	return (size > 0) ? (size) : (1);
}

int			count_size_unsigned_num(ULL num)
{
	short			size;

	size = 0;
	while (num)
	{
		++size;
		num /= 10;
	}
	return (size > 0) ? (size) : (1);
}
