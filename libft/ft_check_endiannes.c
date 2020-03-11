/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_endiannes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:32:32 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:51:01 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					main(void)
{
	unsigned int	i;
	char			*c;

	i = 1;
	c = (char*)&i;
	if (*c)
		ft_putstr("Little endian\n");
	else
		ft_putstr("Big endian\n");
	return (0);
}
