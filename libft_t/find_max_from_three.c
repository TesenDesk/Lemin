/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_from_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 00:30:19 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/05 00:30:36 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

LL	find_max_from_three(LL num1, LL num2, LL num3)
{
	LL max;

	max = 0;
	if ((num1 >= num2) && (num1 >= num3))
		max = num1;
	else if ((num2 >= num1) && (num2 >= num3))
		max = num2;
	else if ((num3 >= num1) && (num3 >= num2))
		max = num3;
	return (max);
}
