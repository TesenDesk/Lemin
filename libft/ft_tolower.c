/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:57:27 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:57:28 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	If it is a symbol of a subset of capital letters of an ASCII set, the
** function converts it to the appropriate lower-case letter, otherwise it
** returns the character itself.
*/

int	ft_tolower(int c)
{
	return (c += ((ft_isupper(c) ? ('a' - 'A') : 0)));
}
