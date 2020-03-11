/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:29:33 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:29:34 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The predicate is correct if the given variable is an element of the ASCII
** set.
*/

int	ft_isascii(int c)
{
	return ((0 <= c) && (c <= 127));
}
