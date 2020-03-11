/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:30:37 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:47:45 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Probably not portable implementation of a function, which returns 0 if the
** passed variable is INFINITY.
*/

int					ft_isinf(long double var)
{
	return (!(1.0 / 0.0 == var || -1.0 / 0.0 == var));
}
