/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_and_delete_graph.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:47:05 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 21:23:52 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

void					delete_links(t_vertex **vertices, int v_size)
{
	t_vertex			*curr;

	while (v_size)
	{
		curr = *(vertices + --(v_size));
		if (curr && curr->name)
			free((void *)curr->name);
		if (curr && curr->links)
			ft_dlstdel(&curr->links, ft_delfunc_dummy);
		ft_memdel((void **)(vertices + v_size));
	}
	return ;
}

void					delete_map(t_hash_map **map)
{
	if (map && *map)
		hm_del(map);
	return ;
}

void					delete_vertices(t_vertex ***vertices)
{
	ft_memdel((void **)vertices);
	return ;
}

void					delete_lines(char ***lines, int l_size)
{
	char			**curr;

	curr = *lines;
	while (l_size)
		ft_memdel((void **)(curr + --l_size));
	ft_memdel((void **)lines);
	return ;
}

void					*free_graph(t_graph *graph)
{
	delete_lines(&graph->reader.lines, graph->reader.l_size);
	delete_links(graph->vertices, graph->v_size);
	delete_vertices(&graph->vertices);
	delete_map(&graph->ret.map);
	return (NULL);
}
