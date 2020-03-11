/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vertex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:24:14 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:19:58 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

t_vertex			*find_vertex(t_hash_map *map, char *name)
{
	t_vertex		*vertex;

	vertex = (t_vertex *)hm_find(map, (void *)name);
	return (vertex);
}

int					find_current_vertices(t_graph *graph)
{
	int				state;

	state = FAILURE;
	if ((graph->edge.vertex_l =
			find_vertex(graph->ret.map, graph->edge.name_l)) &&
			(graph->edge.vertex_r =
				find_vertex(graph->ret.map, graph->edge.name_r)))
		state = SUCCESS;
	return (state);
}
