/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:12:34 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:51:20 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_base(ULL val, U_CHAR base)
{
	int i;

	i = 0;
	if (val)
	{
		while (val)
		{
			val /= base;
			++i;
		}
		return (i);
	}
	else
		return (1);
}

static	int	init_rep(U_CHAR rep[2][16], U_CHAR type)
{
	int i;

	i = 0;
	while (i < 10)
	{
		rep[0][i] = i + '0';
		rep[1][i] = i + '0';
		++i;
	}
	while (i < 16)
	{
		rep[0][i] = i - 10 + 'a';
		rep[1][i] = i - 10 + 'A';
		++i;
	}
	if (type == 'x' || type == 'o' || type == 'p')
		return (0);
	else
		return (1);
}

void		ft_ltoa_base(t_buf_struct *buf_s, uintmax_t value, U_CHAR base)
{
	static U_CHAR	rep[2][16];
	int				shift;
	int				temp;
	int				index;

	shift = 0;
	index = init_rep(rep, B_AR_CUR.type);
	if (base < 2 || base > 16)
		return ;
	temp = count_base(value, base);
	shift += temp;
	if (buf_s->size + shift > BUF_SIZE - 1 - 66)
		print_and_clear(buf_s);
	*(buf_s->buf + buf_s->size + shift + 1) = 0;
	if (value == 0)
		*(buf_s->buf + buf_s->size + --shift) = rep[index][value % base];
	while (value != 0)
	{
		*(buf_s->buf + buf_s->size + --shift) = rep[index][value % base];
		value /= base;
	}
	buf_s->size += temp;
}

void		ft_normal_ltoa(U_CHAR *buf, ULL value)
{
	static char rep[] = "0123456789";
	int			shift;
	int			temp;
	int			i;

	shift = 0;
	i = 0;
	temp = count_base(value, 10);
	shift += temp;
	*(buf + i + shift) = 0;
	if (value == 0)
		*(buf + i + --shift) = rep[value % 10];
	while (value != 0)
	{
		*(buf + i + --shift) = rep[value % 10];
		value /= 10;
	}
}
