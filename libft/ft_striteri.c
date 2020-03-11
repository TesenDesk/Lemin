/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:50:58 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:51:00 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	For each element of the string str applies the function passed by reference.
**	Returns void.
*/

void	ft_striteri(char *str, void (*fptr)(unsigned int, char *))
{
	size_t index;

	if (str && fptr)
	{
		index = 0;
		while (*str != '\0')
			(*fptr)(index++, str++);
	}
	return ;
}
