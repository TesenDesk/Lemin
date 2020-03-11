/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:02:56 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 15:02:58 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function accepts a signed integer to convert it to a character string
** representing the number in the decimal number system. The result of the
** conversion is written to STDOUT. Heap operations are prohibited.
**	Returns void.
*/

void		ft_putnbr(int nbr)
{
	ft_putnbr_fd(nbr, STDOUT);
	return ;
}
