/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:34:19 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:34:20 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The predicate is correct if this variable is an element of a subset of the
** capital letters of the ASCII set.
*/

int	ft_isupper(int c)
{
	return ((c >= 'A') && (c <= 'Z'));
}
