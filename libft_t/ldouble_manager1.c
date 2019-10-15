/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble_manager1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:36:53 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:51:41 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_ldsign(t_def_num *ld_struct)
{
	char	sign;

	sign = ld_struct->point.bytes[9] & ((char)1 << 7);
	ld_struct->point.bytes[9] &= 127;
	return ((sign) ? (1) : (0));
}

int		get_ldexp(t_def_num *ld_struct)
{
	int				exp_num;

	exp_num = 0;
	exp_num |= (ld_struct->point.bytes[8]);
	exp_num |= (int)(ld_struct->point.bytes[9]) << 8;
	if (!(exp_num))
		++exp_num;
	exp_num -= LDEXP_BIAS;
	return (exp_num);
}

ULL		get_ldfrac(t_def_num *ld_struct)
{
	short			pos;
	ULL				frac_num;

	pos = 7;
	frac_num = 0;
	while (pos >= 0)
	{
		frac_num |= (ULL)(ld_struct->point.bytes[pos]) << (8 * pos);
		pos--;
	}
	return (frac_num);
}

U_CHAR	get_ldlength(ULL frac_part)
{
	int		i;
	char	length_count;
	char	pos;

	i = 0;
	length_count = 0;
	pos = 63;
	if (!frac_part)
		return (0);
	while (!(frac_part & (1UL << pos)))
		frac_part <<= 1;
	while (frac_part)
	{
		++i;
		if (frac_part & (1UL << pos))
		{
			length_count += i;
			i = 0;
		}
		frac_part <<= 1;
	}
	return (length_count);
}

void	cut_ld(LD const *ld_num, t_float_part *parted_num)
{
	t_def_num		ld_struct;

	ld_struct.point.ld = *ld_num;
	parted_num->sign = get_ldsign(&ld_struct);
	parted_num->exp_part = get_ldexp(&ld_struct);
	parted_num->frac_part = get_ldfrac(&ld_struct);
	parted_num->frac_length = get_ldlength(parted_num->frac_part);
}
