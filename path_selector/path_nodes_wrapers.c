/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_nodes_wrapers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:16:12 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:16:16 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

/*
**============================NEXT CURR PREV paths==============================
*/

t_dlist			*next_path(t_lines *properties)
{
	return (properties->path_curr->next);
}

t_dlist			*prev_path(t_lines *properties)
{
	return (properties->path_curr->prev);
}

t_dlist			*curr_path(t_lines *properties)
{
	return (properties->path_curr);
}
