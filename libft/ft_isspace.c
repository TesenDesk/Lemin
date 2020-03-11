/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:32:27 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:32:31 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The predicate is correct if the given variable can be mapped to one
** character of the ASCII set, namely: horizontal or vertical tabulation, line
** feed, space, carriage return, page feed.
*/

int	ft_isspace(int c)
{
	return ((c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') || \
			(c == '\r') || (c == ' '));
}
