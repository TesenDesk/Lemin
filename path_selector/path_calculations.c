/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:16:01 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:16:43 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

/*
**===============================path calculations==============================
*/

int				curr_len(t_lines *properties)
{
	int			curr_len;

	curr_len = (curr_path(properties)->flow);
	return (curr_len);
}

void			discharge(t_lines *properties)
{
	properties->charge -= properties->flow;
	return ;
}

int				calculate_criterion(t_lines *properties)
{
	int			criterion;

	criterion = ((curr_len(properties) + 1) *
		(properties->flow) - properties->prev_len_sum);
	return (criterion);
}

int				new_len_sum(t_lines *properties)
{
	int			new_len_sum;

	new_len_sum = (properties->prev_len_sum + curr_len(properties));
	return (new_len_sum);
}

int				is_permitted_curr_path(t_lines *properties)
{
	if (properties->criterion <= properties->charge)
		return (TRUE);
	return (FALSE);
}
