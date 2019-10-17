/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:16:07 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/17 16:23:26 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

t_vertex			*vertex_new(t_graph *graph, int v_size)
{
	t_vertex		*vertex;

	if (!(vertex = (t_vertex *)ft_memalloc(sizeof(*vertex))))
		return (NULL);
	if (graph && (graph->vertices + v_size)->type)
		vertex->type = (graph->vertices + v_size)->type;
	vertex->name = (graph->vertices + v_size)->name;
	return (vertex);
}

t_vertex			*find_vertex(t_hash_map *map, char *name)
{
	t_vertex		*vertex;

	vertex = (t_vertex *)hm_find(map, (void *)name);
	return (vertex);
}