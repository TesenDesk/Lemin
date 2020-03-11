/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:35:30 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/16 18:46:27 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Makes every lowercase letter of the string uppercase letter, or do nothing.
*/

void				ft_strtoupper(char *str)
{
	int				dif;

	dif = 'a' - 'A';
	if (str)
		while (*str)
		{
			if (ft_islower(*str))
				*str -= dif;
			++str;
		}
	return ;
}
