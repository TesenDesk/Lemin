/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:28:27 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:28:28 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The predicate is correct if this variable is an element of at least one of
** the subsets of numbers, uppercase or lowercase letters of the characters of
** the ASCII set.
*/

int	ft_isalnum(int c)
{
	return (ft_isupper(c) || ft_islower(c) || ft_isdigit(c));
}
