/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:54:28 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 17:19:51 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_isdigitnstr(char *str, int n)
{
	int				decision;

	decision = !TRUE;
	if (str)
	{
		if (*str == '+' || *str == '-')
		{
			++str;
			--n;
		}
		while (*str && (n-- > 0))
		{
			decision = ft_isdigit(*str);
			++str;
		}
	}
	return (decision);
}
