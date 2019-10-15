/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_prec_analize_cell.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:05:38 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:49:21 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			analize_frac_cell_z_p_0(t_dec_frac *l_num,
		int index, int *ld_zeros)
{
	if (check_for_fives2(&(l_num->frac), index - 1, 9,
			l_num->frac.l_num[index] % 10) > 0)
	{
		if (check_for_nines(l_num->frac.l_num[index]) > 0)
		{
			if (*ld_zeros > 0)
			{
				l_num->frac.l_num[index] = 1;
				--(*ld_zeros);
			}
			else
			{
				l_num->frac.l_num[index] &= 0;
				rebuild_lnum(l_num, ++index, ld_zeros);
			}
		}
		else
			++l_num->frac.l_num[index];
	}
	clear_lnum_df(&(l_num->frac), index - 1);
}

void			analize_frac_cell(t_dec_frac *l_num, int dif_prec,
		int *ld_zeros, U_CHAR is_zero_cell)
{
	ULL			sub;
	ULL			first_dig;

	first_dig = ((l_num->frac.l_num[l_num->frac.cur] % ft_pow(10, dif_prec + 1))
	- (l_num->frac.l_num[l_num->frac.cur] % ft_pow(10, dif_prec))) /
			ft_pow(10, dif_prec);
	sub = (l_num->frac.l_num[l_num->frac.cur] / ft_pow(10, dif_prec));
	if (dif_prec == 0)
		analize_frac_cell_z_p_0(l_num, l_num->frac.cur, ld_zeros);
	else if (check_for_fives2(&(l_num->frac), l_num->frac.cur,
			dif_prec, first_dig) > 0)
	{
		if (check_for_nines(sub) > 0 && (count_size_fnum(l_num->
		frac.l_num[l_num->frac.cur]) == 9 || is_zero_cell > 0))
			rebuild_frac_cell(l_num, ld_zeros, is_zero_cell);
		else
			l_num->frac.l_num[l_num->frac.cur] = (sub + 1) *
					ft_pow(10, dif_prec);
	}
	else
		l_num->frac.l_num[l_num->frac.cur] = sub * ft_pow(10, dif_prec);
	clear_lnum_df(&(l_num->frac), l_num->frac.cur - 1);
}

void			analize_frac_cell_z_p_0_dec(t_dec_frac *l_num, int index)
{
	if (check_for_fives2(&(l_num->dec), index - 1, 9,
			l_num->dec.l_num[index] % 10) > 0)
	{
		if (check_for_nines(l_num->dec.l_num[index]) > 0)
			rebuild_dec(l_num, index);
		else
			++l_num->dec.l_num[index];
	}
	clear_lnum_df(&(l_num->frac), index - 1);
}

void			analize_frac_cell_dec(t_dec_frac *l_num, int dif_prec)
{
	ULL			sub;
	ULL			f_d;

	f_d = ((l_num->dec.l_num[l_num->dec.cur] % ft_pow(10, dif_prec + 1))
	- (l_num->dec.l_num[l_num->dec.cur] % ft_pow(10, dif_prec))) /
			ft_pow(10, dif_prec);
	sub = (l_num->dec.l_num[l_num->frac.cur] / ft_pow(10, dif_prec));
	if (dif_prec == 0)
		analize_frac_cell_z_p_0_dec(l_num, l_num->dec.cur);
	else if (check_for_fives2(&(l_num->dec), l_num->dec.cur, dif_prec, f_d)
	> 0 || ((l_num->dec.l_num[l_num->dec.cur] % ft_pow(10, dif_prec) -
	l_num->dec.l_num[l_num->dec.cur] % ft_pow(10, dif_prec - 1)) /
	ft_pow(10, dif_prec - 1) == 5
	&& !(is_zero_l_num_norm(&(l_num->frac), l_num->frac.filled - 1))))
	{
		if (check_for_nines(sub) > 0 && (count_size_fnum(l_num->
		dec.l_num[l_num->dec.cur]) == 9))
			rebuild_dec(l_num, l_num->dec.cur);
		else
			l_num->dec.l_num[l_num->dec.cur] = l_num->dec.l_num[l_num->dec.cur]
			+ ft_pow(10, dif_prec);
	}
	else
		l_num->dec.l_num[l_num->dec.cur] = sub * ft_pow(10, dif_prec);
	clear_lnum_df(&(l_num->dec), l_num->dec.cur - 1);
}
