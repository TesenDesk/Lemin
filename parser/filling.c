/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:13:52 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:25:41 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

void				set_type_and_price_by_type(t_vertex *vertex, int *type)
{
	vertex->type = *type;
	if (!*type)
		vertex->price = -1;
	else
	{
		if (*type == SINK)
			vertex->price = (*type == SINK) ? INT_MAX : 0;
	}
	*type = NORMAL;
	return ;
}

void				if_unique_copy_dst_src(t_graph *graph, t_vertex *vertex)
{
	if (vertex->type)
	{
		if (vertex->type == SINK)
		{
			if (graph->ret.v_sink)
				graph->reader.state = ERROR;
			else
				graph->ret.v_sink = vertex;
		}
		else if (vertex->type == SOURCE)
		{
			if (graph->ret.v_source)
				graph->reader.state = ERROR;
			else
				graph->ret.v_source = vertex;
		}
	}
	return ;
}

t_vertex			*carefully_parse(t_graph *graph)
{
	char			*name;
	char			*x;
	char			*y;
	t_vertex		*vertex;

	name = graph->reader.line;
	if (!(vertex = (t_vertex *)ft_memalloc(sizeof(*vertex))) ||
			!(x = ft_strchr(name, ' ')) ||
			!(vertex->name = ft_strsub(name, 0, x++ - name)) ||
			ft_strchr(vertex->name, '-') ||
			!(y = ft_strchr(x, ' ')) ||
			fill_nbr_field_if_possible(x, y++ - x, &vertex->x) == FAILURE ||
			fill_nbr_field_if_possible(y, ft_strlen(y), &vertex->y) == FAILURE
			|| (graph->reader.type == SINK && graph->ret.v_sink)
			|| (graph->reader.type == SOURCE && graph->ret.v_source))
		graph->reader.state = ERROR;
	return (vertex);
}

int					carefully_parse_then_fill_vertex(t_graph *graph)
{
	t_vertex		*vertex;

	vertex = carefully_parse(graph);
	if (graph->reader.state != ERROR)
	{
		set_type_and_price_by_type(vertex, &graph->reader.type);
		if_unique_copy_dst_src(graph, vertex);
		if (graph->reader.state != ERROR)
			graph->reader.state = PARSE_NORMAL;
	}
	*(graph->vertices + graph->v_size) = vertex;
	if ((++graph->v_size) == graph->max_size)
		if (reallocate_vertices(graph) == FAILURE)
			graph->reader.state = ERROR;
	return (graph->reader.state);
}
