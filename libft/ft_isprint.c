/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:34:00 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:34:02 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The predicate is correct if the given variable is an element of the
** printing symbols of the ASCII set.
*/

int	ft_isprint(int c)
{
	return ((c >= 32) && (c <= 126));
}
