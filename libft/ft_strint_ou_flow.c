/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strint_ou_flow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:12:39 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/31 15:05:16 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*travers_nbr_str(char *str)
{
	while (ft_isdigit(*str))
		++str;
	return (str);
}

int					ft_strint_ou_flow(char *str, int *nbr)
{
	char			*top;
	char			*tip;

	if (!str || !nbr)
		return (FAILURE);
	if ((*nbr = ft_atoi(str)) == INT_MAX || *nbr == INT_MIN)
	{
		top = str;
		if (*top == '+' || *top == '-')
			++top;
		if (!(top = ft_strchr_no(top, '0')))
			return (FAILURE);
		tip = travers_nbr_str(top);
		if ((ft_strncmp("214748364", top, tip - top)) ||
				(*(top + 9) != '7' && (nbr > 0)) ||
				(*(top + 9) != '8' && (nbr < 0)))
			return (FAILURE);
	}
	return (SUCCESS);
}
