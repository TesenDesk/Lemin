/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:30:53 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:30:56 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The predicate is correct if this variable is an element of a subset of the
** characters in lower case letters of the ASCII set.
*/

int	ft_islower(int c)
{
	return ((c >= 'a') && (c <= 'z'));
}
