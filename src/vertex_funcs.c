/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:16:07 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/15 17:53:38 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

t_vertex			*vertex_new(t_graph *graph)
{
	t_vertex		*vertex;

	if (!(vertex = (t_vertex *)ft_memalloc(sizeof(*vertex))))
		return (NULL);
	if (graph && graph->vertices->type)
		vertex->type = graph->vertices->type;
	return (vertex);
}

t_vertex			*find_vertex(t_hash_map *map, char *name)
{
	t_vertex		*vertex;

	vertex = (t_vertex *)hm_find(map, (void *)name);
	return (vertex);
}