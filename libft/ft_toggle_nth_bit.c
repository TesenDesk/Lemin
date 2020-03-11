/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_nth_bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:57:11 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:57:12 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Switches the nth bit to the opposite value.
** Works only to 2^31 - 1 (or till UINT_MAX / 2 - 1).
*/

int	ft_set_nth_bit(int x, int n)
{
	return (x |= (1 << n));
}
