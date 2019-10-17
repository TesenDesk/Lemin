/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:56:40 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/17 13:55:27 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

int					ft_isdigitstr(char *str)
{
	int				decision;

	decision = !TRUE;
	if (str)
	{
		str += (*str == '+' || *str == '-') ? 1 : 0;
		while (*str && ft_isdigit(*str))
			++str;
		decision = !*str ? TRUE : !TRUE; 
	}
	return (decision);
}
