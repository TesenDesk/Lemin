/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_common_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:36:58 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 22:40:12 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int				ant_name(t_lines *properties, int i)
{
	int			name;

	name = properties->initial_charge - properties->charge -
			(i - properties->flow) + 1;
	return (name);
}

int				push_ants_bunch_to_paths_and_move_them(t_lines *properties)
{
	t_dlist		*curr;
	t_dlist		*back;
	int			i;

	curr = first_path(properties);
	back = curr_path(properties)->next;
	i = properties->flow;
	while (TRUE)
	{
		if (!ft_ddeq_new_a(&properties->moves, (void *)a_path(curr), TRUE))
			return (FAILURE);
		properties->moves->a->prev->content_size = properties->flow - i;
		properties->moves->a->prev->flow = ant_name(properties, i--);
		if ((curr = curr->next) == back)
			break ;
	}
	move_ants_and_print(properties);
	return (SUCCESS);
}

void			print_ants_moves(t_lines *properties)
{
	find_largest_permitted_path_its_criterion_and_flow(properties);
	push_ants_bunch_to_paths_and_move_them(properties);
	discharge(properties);
	while (properties->charge)
	{
		determine_flow(properties);
		push_ants_bunch_to_paths_and_move_them(properties);
		discharge(properties);
	}
	while (properties->moves->a)
		move_ants_and_print(properties);
	return ;
}
