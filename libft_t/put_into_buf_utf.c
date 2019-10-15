/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_into_buf_utf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:20:03 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:53:54 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_utf(t_buf_struct *buf_s, int ch)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	tmp = (char*)&ch;
	len = find_utf_len(ch);
	adjust_utf_num(&ch, len);
	tmp += len - 1;
	while (i < len)
	{
		char_to_buf(buf_s, *tmp);
		--tmp;
		++i;
	}
}

int		find_utf_len(int ch)
{
	int	len;

	len = 0;
	if (ch <= 0x7F)
		len = 1;
	else if (ch <= 0x7FF)
		len = 2;
	else if (ch <= 0xFFFF)
		len = 3;
	else
		len = 4;
	return (len);
}

void	adjust_utf_num(int *ch, int len)
{
	if (len == 2)
		*ch = ((*ch & 0xBF) | 0x80) | (((*ch & 0x7C0) << 2) | 0xC000);
	else if (len == 3)
		*ch = ((((*ch & 0xBF) | 0x80) | (((*ch << 2) & 0x3F00) | 0x8000))
		| (((*ch & 0xF000) << 4) | 0xE00000));
	else if (len == 4)
		*ch = (((((*ch & 0xBF) | 0x80) | (((*ch << 2) & 0x3F00) | 0x8000))
		| (((*ch & 0x3F000) << 4) | 0x800000))) |
		(((*ch & 0x7000000) << 6) | 0xF0000000);
}
