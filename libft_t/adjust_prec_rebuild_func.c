/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_prec_rebuild_func.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:17:01 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:49:38 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rebuild_frac_cell(t_dec_frac *l_num, int *ld_zeros, int is_zero_cell)
{
	if (is_zero_cell <= 0)
	{
		l_num->frac.l_num[l_num->frac.cur] &= 0;
		rebuild_lnum(l_num, ++l_num->frac.cur, ld_zeros);
	}
	else
	{
		l_num->frac.l_num[l_num->frac.cur] = *ld_zeros <= 0 ? (0) : (1);
		if (*ld_zeros <= 0)
			rebuild_dec(l_num, 0);
		else
			--(*ld_zeros);
	}
}

void	rebuild_dec(t_dec_frac *l_num, int dec_index)
{
	while ((count_size_fnum(l_num->dec.l_num[dec_index]) == 9) &
	(check_for_nines(l_num->dec.l_num[dec_index]) > 0) &
	(dec_index < (int)(l_num->dec.filled - 1)))
		l_num->dec.l_num[dec_index++] &= 0;
	if (dec_index < (int)(l_num->dec.filled - 1))
		l_num->dec.l_num[dec_index] += 1;
	else if (dec_index == (int)(l_num->dec.filled - 1))
	{
		if ((l_num->dec.filled > 1) || ((l_num->dec.filled == 1) &
		(check_for_nines(l_num->dec.l_num[dec_index]) > 0)
		& (count_size_fnum(l_num->dec.l_num[dec_index]) == 9)))
		{
			l_num->dec.l_num[dec_index++] &= 0;
			l_num->dec.l_num[dec_index] = 1;
			l_num->dec.filled += 1;
		}
		else if ((l_num->dec.filled == 1) & (count_size_fnum(l_num->
		dec.l_num[dec_index] < 9)))
			l_num->dec.l_num[dec_index] += 1;
	}
}

void	rebuild_lnum(t_dec_frac *l_num, int index, int *ld_zeros)
{
	while ((index < (int)(l_num->frac.filled - 1)) &
	(l_num->frac.l_num[index] == 999999999))
		l_num->frac.l_num[index++] &= 0;
	if (index < (int)(l_num->frac.filled - 1))
		l_num->frac.l_num[index] += 1;
	else if (index == (int)(l_num->frac.filled - 1))
	{
		if (check_for_nines(l_num->frac.l_num[index]) > 0)
		{
			if (*ld_zeros == 0)
			{
				l_num->frac.l_num[index] &= 0;
				rebuild_dec(l_num, 0);
			}
			else
			{
				--(*ld_zeros);
				l_num->frac.l_num[index] = 1;
			}
		}
		else
			++(l_num->frac.l_num[index]);
	}
	else
		rebuild_dec(l_num, 0);
}
