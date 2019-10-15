/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:23:59 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/10 21:21:11 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

/*
**						   ft_imaxtostr().
**						____________________
**	PURPOSE:
**	The function translates representations of numbers from memory into a given
** number system (from 2 to 36). By default, it accepts unsigned integers,
** however, by controlling the fourth parameter, you can specify the operation
** with a sign.
**	ARGUMENTS:
**		str		: buffer for writing the result string. If empty, then skipping
**				computations, a pointer to the string is returned.
**		nbr		: the number to be converted.
**		radix	: the base of the number system. If equal to 0, then equal to
**				10. If equal to 1 or greater than 36, only zero byte is written
**				to the string.
**		issign: = 1 if there is a sign, otherwise! = 0.
**	OUTPUT:
**				: Pointer to the end of line character.
*/

static int		prepare(char *str, uintmax_t *nbr, t_ui *radix, int *issign)
{
	int			isnegative;

	isnegative = !TRUE;
	if (!str || *radix == 1 || *radix > 36)
	{
		if (str)
			*str = '\0';
		return (FAILURE);
	}
	if (!*radix)
		*radix = 10;
	if (*issign && *nbr > (uintmax_t)INTMAX_MAX)
		isnegative = !!TRUE;
	if (isnegative)
		*nbr = (uintmax_t)((-(intmax_t)(*nbr)));
	else
		*issign = !TRUE;
	return (SUCCESS);
}

char			*ft_imaxtostr(char *str, uintmax_t nbr, t_ui radix, int issign)
{
	t_uimaxdiv	div_r;
	char		*radix_cyphers;
	char		*zero;

	if (prepare(str, &nbr, &radix, &issign))
		return (str);
	zero = str;
	radix_cyphers = "0123456789abcdefghijklmnopqrstuvwxyz";
	div_r = ft_uimaxdiv(nbr, radix);
	while (div_r.quot)
	{
		*zero++ = *(radix_cyphers + div_r.rem);
		div_r = ft_uimaxdiv(div_r.quot, radix);
	}
	*zero++ = *(radix_cyphers + div_r.rem);
	if (issign)
		*zero++ = '-';
	*zero = '\0';
	ft_strrev(str);
	return (zero);
}
