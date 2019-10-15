/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_middle_from_three.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:53:32 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/05 00:33:24 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

LL		find_middle_from_three(LL num1, LL num2, LL num3)
{
	LL	middle;

	middle = 0;
	if (((num1 <= num2) && (num1 >= num3)) ||
	((num1 >= num2) && (num1 <= num3)))
		middle = num1;
	else if (((num2 <= num1) && (num2 >= num3)) ||
	((num2 >= num1) && (num2 <= num3)))
		middle = num2;
	else if (((num3 <= num1) && (num3 >= num2)) ||
	((num3 >= num1) && (num3 <= num2)))
		middle = num3;
	return (middle);
}
