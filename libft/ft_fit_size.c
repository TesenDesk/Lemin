/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:25:52 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:25:53 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function monitors that the final value of the first parameter is not
** greater than UINT_MAX and at the same time be sufficient to accommodate the
** already existing value and its increase by some specified step. The new value
** is selected in accordance with the powers of two, rounded up.
*/

int	ft_fit_size(ssize_t *bank_size, ssize_t line_size, ssize_t step)
{
	ssize_t	min_new_size;

	if (step <= 0 || step > UINT_MAX ||
		UINT_MAX - line_size < step || *bank_size > UINT_MAX)
		return (ERROR);
	if (*bank_size >= (min_new_size = ft_powerof2roundup(line_size + step)))
		return (NOCHANGES);
	*bank_size = min_new_size;
	return (SUCCESS);
}
