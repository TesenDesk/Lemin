/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:54:28 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/17 13:55:27 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

int					ft_isdigitnstr(char *str, int n)
{
	int				decision;

	decision = !TRUE;
	if (str)
	{
		str += (*str == '+' || *str == '-') ? 1 : 0;
		while (*str && n-- && ft_isdigit(*str))
			++str;
		decision = !*str ? TRUE : !TRUE; 
	}
	return (decision);
}
