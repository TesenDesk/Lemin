/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldouble_manager2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:09:21 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:51:48 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					manage_ldouble_num(t_buf_struct *buf_s)
{
	t_float_part			p_n;
	t_dec_frac				l_num;
	t_fptr_floatoperation	operations[2];
	size_t					tmp;

	initdec_frac(&l_num);
	initfptr_operations(operations);
	cut_ld(&B_AR_CUR.l_dnum, &p_n);
	B_AR_CUR.sign = p_n.sign;
	if (B_AR_CUR.sign > 0)
		B_AR_CUR.SPACE_FLAG &= 0;
	if (check_for_inf_nan(buf_s, &p_n) > 0)
		return ;
	count_ld_num(buf_s, &p_n, &l_num);
	count_exp_pow(buf_s, &l_num);
	adjust_fnum_prec(buf_s, &l_num);
	tmp = (count_dec_frac_digs(&(l_num.dec)));
	tmp = tmp ? tmp : 1;
	B_AR_CUR.dec_size = B_AR_CUR.type == 'f' ? tmp : 1;
	B_AR_CUR.len = tmp + B_AR_CUR.prec;
	if (B_AR_CUR.prec || B_AR_CUR.HASH_FLAG)
		++B_AR_CUR.len;
	adjust_num_width(buf_s);
	put_ldouble(buf_s, &l_num, chosefloatfunc(buf_s, operations));
}

t_fptr_floatoperation	chosefloatfunc(t_buf_struct *buf_s,
		t_fptr_floatoperation operations[2])
{
	if (B_AR_CUR.type == 'f' || B_AR_CUR.type == 'F')
		return (operations[0]);
	else
		return (operations[1]);
}

void					initfptr_operations(t_fptr_floatoperation *operations)
{
	operations[0] = put_ldouble_num;
	operations[1] = put_ldouble_exp;
}
