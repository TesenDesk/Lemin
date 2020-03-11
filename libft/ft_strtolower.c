/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:46:45 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/16 18:47:33 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Makes every uppercase letter of the string lowercase letter, or do nothing.
*/

void				ft_strtolower(char *str)
{
	int				dif;

	dif = 'a' - 'A';
	if (str)
		while (*str)
		{
			if (ft_isupper(*str))
				*str += dif;
			++str;
		}
	return ;
}
