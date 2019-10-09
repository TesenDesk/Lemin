/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_from_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 00:31:34 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/05 00:31:40 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

LL		find_min_from_three(LL num1, LL num2, LL num3)
{
	LL	min;

	min = 0;
	if ((num1 <= num2) && (num1 <= num3))
		min = num1;
	else if ((num2 <= num1) && (num2 <= num3))
		min = num2;
	else if ((num3 <= num1) && (num3 <= num2))
		min = num3;
	return (min);
}
