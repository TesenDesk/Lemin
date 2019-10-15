/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:40:54 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:53:22 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_and_clear(t_buf_struct *buf_s)
{
	int		i;

	i = 0;
	write(1, (U_CHAR*)buf_s->buf, buf_s->size);
	buf_s->counter += buf_s->size;
	buf_s->size = 0;
}

int			ft_checkbit(long long n, int pos)
{
	return ((n & (1UL << pos)) != 0);
}

void		ft_printbits(ULL n, int count)
{
	while (count--)
	{
		ft_putchar(ft_checkbit(n, count) + '0');
		if (!(count % 4 && count))
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void		print_bytes(t_def_num *ld)
{
	int i;

	i = 15;
	while (i >= 0)
		ft_printbits(ld->point.bytes[i--], 8);
}
