/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:35:00 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:35:02 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function takes an array of sufficient size to write the decimal
** representation of an int type as a string of characters. The array must be
** initialized with null characters. Another parameter is the same number that
** will be converted.
**	Returns a pointer to the result string.
*/

char	*ft_itostr(int nbr, char *str)
{
	char	*s;
	int		pow;
	int		n;

	s = str;
	pow = 9;
	if (nbr == MIN_INT)
		return (ft_memcpy(str, "-2147483648", 12));
	if (nbr < 0)
	{
		*s++ = '-';
		nbr *= (-1);
	}
	while ((pow) && !(nbr / ft_power(10, pow)))
		pow--;
	while (pow >= 0)
	{
		n = ft_power(10, pow--);
		*s++ = nbr / n + '0';
		nbr %= n;
	}
	*s = '\0';
	return (str);
}
