/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:35:40 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 00:29:11 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int						initialize_graph_and_allocate_vertices(t_graph *graph)
{
	graph->max_size = BEST_SIZE > 0 ? BEST_SIZE : 4096;
	graph->reader.l_max = BEST_SIZE > 0 ? BEST_SIZE : 4096;
	if (!(graph->vertices = (t_vertex **)ft_memalloc(graph->max_size *
			sizeof(*graph->vertices))) ||
			!(graph->reader.lines = (char **)ft_memalloc(graph->reader.l_max *
			sizeof(*graph->reader.lines))))
		return (FAILURE);
	return (SUCCESS);
}

int						reallocate_vertices(t_graph *graph)
{
	int					size;
	t_vertex			**v_cpy;

	size = (sizeof(*graph->vertices));
	if (graph->max_size > (long)INT_MAX / (2 * size))
		return (FAILURE);
	else
		graph->max_size *= 2;
	if (!(v_cpy = (t_vertex **)ft_memalloc(graph->max_size * size)))
		return (FAILURE);
	ft_memcpy(v_cpy, graph->vertices, graph->v_size * size);
	ft_swap(&v_cpy, &graph->vertices, sizeof(v_cpy));
	free((void *)v_cpy);
	return (SUCCESS);
}

int						reallocate_lines(t_graph *graph)
{
	int					size;
	char				**lines_cpy;

	size = (sizeof(*graph->reader.lines));
	if (graph->reader.l_max > (long)INT_MAX / (2 * size))
		return (FAILURE);
	else
		graph->reader.l_max *= 2;
	if (!(lines_cpy = (char **)ft_memalloc(graph->reader.l_max * size)))
		return (FAILURE);
	ft_memcpy(lines_cpy, graph->reader.lines, graph->reader.l_size * size);
	ft_swap(&lines_cpy, &graph->reader.lines, sizeof(lines_cpy));
	free((void *)lines_cpy);
	return (SUCCESS);
}

int						map_creation_interface(t_graph *graph)
{
	int					state;
	int					ret;

	if ((state = initialize_graph_and_allocate_vertices(graph)) == SUCCESS)
	{
		if ((ret = parsing_input_and_map_filling_manager(graph)) != END_READ ||
				(ret == END_READ && !*graph->vertices) ||
				!graph->ret.v_source->links || !graph->ret.v_sink->links)
			state = FAILURE;
	}
	return (state);
}
