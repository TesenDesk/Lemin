/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strint_ou_flow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:12:39 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/10 21:22:06 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

int					ft_strint_ou_flow(char *str, int *nbr)
{
	char			nbr_str[LONGINTSTR_MAX + 1];
	int				nbr_len;

	ft_bzero(nbr_str, LONGINTSTR_MAX + 1);
	nbr_len = ft_strlen(str);
	if (nbr_len > 11)
		return (FAILURE);
	else
		*nbr = ft_atoi(str);
	if (nbr_len >= 10)
	{
		(void)ft_imaxtostr(nbr_str, *nbr, 10, 1);
		if (ft_strcmp(str, nbr_str))
			return (FAILURE);
	}
	return (SUCCESS);
}
