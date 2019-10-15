/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distinct_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 11:53:23 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 23:51:00 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_integer(U_CHAR ch)
{
	return (ch == 'd' || ch == 'D' || ch == 'i' || ch == 'o' ||
	ch == 'O' || ch == 'x' || ch == 'X' || ch == 'u'
	|| ch == 'U' || ch == 'p');
}

int		is_signed_int(U_CHAR ch)
{
	return (ch == 'd' || ch == 'D' || ch == 'i');
}

int		is_string(U_CHAR ch)
{
	return (ch == 's' || ch == 'S');
}

int		is_floating(U_CHAR ch)
{
	return (ch == 'f' || ch == 'F' || ch == 'g' || ch == 'G' ||
	ch == 'e' || ch == 'E');
}

int		is_unsigned(U_CHAR ch)
{
	return (ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U' || ch == 'x'
	|| ch == 'X');
}
