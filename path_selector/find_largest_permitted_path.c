/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_largest_permitted_path.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:15:54 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:16:48 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

static int		initialy_upgrade_criterion_path_flow(t_lines *properties)
{
	properties->criterion = 1;
	properties->prev_len_sum = properties->min_len;
	++properties->flow;
	return (SUCCESS);
}

static int		upgrade_criterion_path_flow(t_lines *properties)
{
	int			criterion_curr;

	if (next_path(properties) != first_path(properties))
	{
		promote_curr_path_to_next(properties);
		properties->prev_len_sum += curr_len(properties);
	}
	else
		return (FAILURE);
	++properties->flow;
	if ((criterion_curr = calculate_criterion(properties)) >
			properties->charge)
	{
		--properties->flow;
		properties->prev_len_sum -= curr_len(properties);
		promote_curr_path_to_prev(properties);
		return (FAILURE);
	}
	properties->criterion = criterion_curr;
	return (SUCCESS);
}

void			find_largest_permitted_path_its_criterion_and_flow(
					t_lines *properties)
{
	initialy_upgrade_criterion_path_flow(properties);
	while (TRUE)
		if (upgrade_criterion_path_flow(properties) == FAILURE)
			break ;
	return ;
}
