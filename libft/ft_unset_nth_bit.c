/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_nth_bit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:57:54 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:57:56 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Replaces the n-th bit (the first is considered to be zero) by 0.
** Works only to 2^31 - 1 (or till UINT_MAX / 2 - 1).
*/

int	ft_unset_nth_bit(int x, int n)
{
	return (x &= ~(1 << n));
}
