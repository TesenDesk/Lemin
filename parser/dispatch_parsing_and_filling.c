/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_parsing_and_filling.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:16:44 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 21:11:40 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					read_and_allocate_line(t_read *reader, t_graph *graph)
{
	if ((reader->gnl = ft_get_next_line(reader->fd, &reader->line)) <= 0 ||
			*reader->line == 'L')
		reader->state = !reader->gnl ? END_READ : READ_ERROR;
	*(reader->lines + reader->l_size) = reader->line;
	if ((++reader->l_size) == reader->l_max)
		if (reallocate_lines(graph) == FAILURE)
			reader->state = ERROR;
	return (reader->state);
}

void				delete_line(t_read *reader)
{
	ft_memdel((void **)&reader->line);
	return ;
}

t_parse				*parse_dispatcher(int state)
{
	static t_parse	ar[] = {parse_ants,
							parse_normal,
							rough_parse_vertex,
							rough_parse_edge};

	return (ar + state);
}

t_fill				*map_filling_dispatcher(int state)
{
	static t_fill	ar[] = {error_before_filling,
							fill_ants,
							skip_filling,
							skip_filling,
							carefully_parse_then_fill_vertex,
							create_map_fill_vertices_and_an_edge,
							skip_edge_filling,
							fill_edge};

	return (ar + state);
}

int					parsing_input_and_map_filling_manager(t_graph *graph)
{
	while (graph->reader.state != ERROR && graph->reader.state != END_READ &&
		graph->reader.state != READ_ERROR)
	{
		read_and_allocate_line(&graph->reader, graph);
		if (graph->reader.state != READ_ERROR &&
				graph->reader.state != END_READ)
		{
			(*parse_dispatcher(graph->reader.state))(&graph->reader);
			(*map_filling_dispatcher(graph->reader.state))(graph);
		}
		graph->reader.line = NULL;
	}
	return (graph->reader.state);
}
