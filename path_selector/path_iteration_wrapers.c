/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_iteration_wrapers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:16:07 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:16:39 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

/*
**===============================head of paths==================================
*/

t_dlist			*first_path(t_lines *properties)
{
	return (properties->paths);
}

/*
**================================path promotion================================
*/

t_dlist			*promote_curr_path_to_next(t_lines *properties)
{
	return ((properties->path_curr = properties->path_curr->next));
}

t_dlist			*promote_curr_path_to_prev(t_lines *properties)
{
	return ((properties->path_curr = properties->path_curr->prev));
}
