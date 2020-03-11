/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_flow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:15:49 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:17:17 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

void			downgrade_criterion_path_flow(t_lines *properties)
{
	properties->prev_len_sum -= curr_len(properties);
	--properties->flow;
	promote_curr_path_to_prev(properties);
	properties->criterion = calculate_criterion(properties);
	return ;
}

void			determine_flow(t_lines *properties)
{
	while (!is_permitted_curr_path(properties))
	{
		downgrade_criterion_path_flow(properties);
		if (curr_path(properties) == first_path(properties))
			break ;
	}
	return ;
}
