/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:15:43 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:15:44 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int				count_steps(t_lines *properties)
{
	int			steps;

	find_largest_permitted_path_its_criterion_and_flow(properties);
	discharge(properties);
	steps = 1;
	while (properties->charge)
	{
		determine_flow(properties);
		discharge(properties);
		++steps;
	}
	return (steps);
}
