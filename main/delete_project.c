/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_project.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:02:21 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 00:22:04 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"
#include "lemin_my.h"

void					free_the_project(t_lines *properties, t_graph *graph)
{
	if (properties->paths)
		paths_del(properties->paths);
	if (properties->moves)
		ft_ddeqdel(&properties->moves, ft_delfunc_dummy);
	free_graph(graph);
	if (graph->reader.fd)
		close(graph->reader.fd);
	return ;
}
