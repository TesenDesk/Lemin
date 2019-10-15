/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_snum_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:39:48 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/05 00:33:48 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t			ft_count_snum_size(long long k)
{
	int size;

	size = 0;
	while (k != 0)
	{
		k /= 10;
		++size;
	}
	return ((size > 0) ? (size) : (1));
}
