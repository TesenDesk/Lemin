/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:30:28 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:51:28 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	t_buf_struct	buf_s;
	U_CHAR			*tmp;
	va_list			ap;
	U_CHAR			malloc_on;

	tmp = (U_CHAR*)format;
	malloc_on = 0;
	va_start(ap, format);
	if (!(init_arg_ar(&buf_s, (U_CHAR *)format, &ap, &malloc_on)))
		return (-1);
	buf_s.ar_current = 0;
	while ((*tmp))
	{
		read_str(&tmp, &buf_s);
		form_str_from_arg(&buf_s, &tmp);
		++(buf_s.ar_current);
	}
	va_end(ap);
	print_and_clear(&buf_s);
	if (malloc_on > 0)
		free(buf_s.arg_ar);
	return (buf_s.counter);
}

size_t	count_args(char const *format)
{
	size_t		i;
	U_CHAR		*tmp;
	U_CHAR		*check;

	i = 0;
	tmp = (U_CHAR*)format;
	check = NULL;
	while (*tmp)
	{
		check = tmp;
		if (*tmp == '%')
		{
			fill_type_shift(&tmp);
			if (!(check_for_spec(*(tmp))))
				;
			else
				++i;
		}
		else
			++tmp;
	}
	return (i);
}

int		init_arg_ar(t_buf_struct *buf_s, U_CHAR *format, va_list *ap,
		U_CHAR *malloc_on)
{
	size_t	i;

	i = 0;
	ft_bzero(buf_s, sizeof(*buf_s));
	buf_s->arg_num = count_args((char const *)format);
	if (!(buf_s->arg_num))
		return (1);
	if (!(buf_s->arg_ar = (t_arg_opt*)malloc((buf_s->arg_num) *
			sizeof(t_arg_opt))))
		return (0);
	*malloc_on = 1;
	while (i < buf_s->arg_num)
	{
		ft_bzero(buf_s->arg_ar + i, sizeof(buf_s->arg_ar[i]));
		++i;
	}
	fill_arg_ar(buf_s, format, ap);
	return (1);
}

void	fill_arg_ar(t_buf_struct *buf_s, U_CHAR *format, va_list *ap)
{
	U_CHAR	*tmp;

	tmp = (U_CHAR*)format;
	while (*tmp)
		if (*tmp == '%')
		{
			process_arg(buf_s, &tmp, ap);
			++buf_s->ar_current;
		}
		else
			++tmp;
	buf_s->ar_current = 0;
	while (buf_s->ar_current < buf_s->arg_num)
	{
		fill_content(buf_s->arg_ar, buf_s->ar_current, ap);
		if (B_AR_CUR.l_dnum < 0 || B_AR_CUR.l_num < 0)
		{
			B_AR_CUR.SPACE_FLAG = 0;
			B_AR_CUR.sign = 1;
			if (B_AR_CUR.l_num < 0 && (B_AR_CUR.type == 'd' ||
			B_AR_CUR.type == 'i' || B_AR_CUR.type == 'D'))
				B_AR_CUR.l_num *= -1;
		}
		++(buf_s->ar_current);
	}
}

int		process_arg(t_buf_struct *buf_s, U_CHAR **format_str, va_list *ap)
{
	size_t			index;

	++(*format_str);
	index = fill_params(format_str, buf_s->arg_ar, buf_s->ar_current);
	fill_type(*format_str, buf_s->arg_ar, buf_s->ar_current);
	fill_flags(format_str, buf_s->arg_ar, buf_s->ar_current);
	fill_width(format_str, buf_s->arg_ar, buf_s->ar_current, ap);
	fill_precision(format_str, buf_s->arg_ar, buf_s->ar_current, ap);
	if (B_AR_CUR.PLUS_FLAG)
		B_AR_CUR.SPACE_FLAG = 0;
	if (B_AR_CUR.prec && (B_AR_CUR.type == 'd' || B_AR_CUR.type == 'i' ||
	B_AR_CUR.type == 'x' || B_AR_CUR.type == 'X' || B_AR_CUR.type == 'o' ||
	B_AR_CUR.type == 'O'))
		B_AR_CUR.ZERO_FLAG = 0;
	fill_mod(format_str, buf_s->arg_ar, buf_s->ar_current);
	++(*format_str);
	return (1);
}
