/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arythmetic3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 00:22:24 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:52:38 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** void				long_free(t_long_num *num)
** {
** 	if (num)
** 	{
** 		free(num->l_num);
** 		free(num);
** 	}
** }
*/

U_CHAR				count_size_fnum(ULL num)
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

void				long_copy(t_long_num *l1, ULL *res, size_t size_to_copy)
{
	size_t			pos;

	pos = 0;
	while (pos < size_to_copy)
	{
		(*l1).l_num[pos] = *(res + pos);
		++pos;
	}
	l1->filled = size_to_copy;
}

void				long_zero(t_long_num *num)
{
	size_t			pos;

	pos = 0;
	while (pos < (*num).filled)
		(*num).l_num[pos++] = 0;
	(*num).filled = 0;
}

void				long_num_zero(ULL *num, size_t filled)
{
	size_t			pos;

	pos = 0;
	while (pos < filled)
		*(num + pos++) = 0;
}
