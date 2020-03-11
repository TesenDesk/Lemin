/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_and_filling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:33:47 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 23:02:15 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					fill_map_with_vertices(t_graph *graph)
{
	int				v_size;
	static char		*line;

	v_size = graph->v_size;
	while (v_size--)
	{
		if (find_vertex(graph->ret.map, graph->vertices[v_size]->name) ||
				!hm_put(&graph->ret.map,
					(void *)(graph->vertices[v_size]->name),
					(void *)graph->vertices[v_size]))
		{
			while (ft_get_next_line(graph->reader.fd, &line) > 0)
				ft_memdel((void **)&line);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int					create_map(t_hash_map **map, int v_size)
{
	return (!(*map = create_hashmap(v_size)) ? FAILURE : SUCCESS);
}

int					create_map_fill_vertices_and_an_edge(t_graph *graph)
{
	if (!*graph->vertices || !graph->ret.v_source || !graph->ret.v_sink ||
			create_map(&graph->ret.map, graph->v_size) == FAILURE ||
			fill_map_with_vertices(graph) == FAILURE)
		graph->reader.state = ERROR;
	else
	{
		graph->reader.state = FILL_EDGE;
		fill_edge(graph);
	}
	return (graph->reader.state);
}
