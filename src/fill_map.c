/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:50:49 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/17 16:29:03 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

// TODO: 
// t_dlist content пусть хранить указатель на vertex структуру с именем.
// При освобождении Карты нужно освобождать связные списки и имена!

int					resize_vertices(t_graph *graph, int *state)
{
	if (!(graph->vertices = (t_vertices *)ft_realloc(graph->vertices,
			graph->v_size, (graph->max_size *= 2))))
		*state = ERROR;
	return (*state == ERROR ? FAILURE : SUCCESS);
}

void				exit_procedure(t_graph *graph, char **line, int *state,
		t_hash_map **map)
{
	int				i;
	t_vertices		*v;

	// Осовобождение списков смежности не реализовано.
	i = graph->v_size;
	v = graph->vertices;
	while (i)
		free((void *)(v + --i));
	ft_memdel((void **)&v);
	(void)map;
//	hm_del(map);
	if (line && *line)
		ft_memdel((void **)line);
	*state = ERROR;
 	return ;
 }

int					parse_lines(t_graph *graph, t_hash_map **map)
{
	int				gnl_ret;
	int				state;
	static char		*line;

	state = WAIT_NBR;
	while ((gnl_ret = get_next_line(STDIN, &line)) > 0 && state != ERROR)
		if (*line == 'L' ||
				(state = (*parse_dispatcher(state))(graph, &line)) == ERROR ||
				state == WAIT_EDGE)
					break ;
	if (state == WAIT_EDGE)
	{
		if (!(*map = createHashmap(graph->v_size)) ||
				fill_map_with_vertices(graph, &line, &state, map) == FAILURE)
			exit_procedure(graph, &line, &state, map);
		while ((gnl_ret = get_next_line(STDIN, &line)) > 0 && state != ERROR)
		{
			if (iscomment(line))
			{
				ft_memdel((void **)&line);
				continue ;
			}
			put_edges(&line, map);
		}
	}
	else
	{
		state = ERROR;
		exit_procedure(graph, &line, &state, map);
	}
	return (!gnl_ret && state != ERROR ? SUCCESS : FAILURE);
}

t_fill_return		fill_map(void)
{
	t_graph			graph;

	ft_bzero((void *)&graph, sizeof(graph));
	graph.max_size = BEST_SIZE > 0 ? BEST_SIZE : 4096;
	graph.ret.map = NULL;
	if (!(graph.vertices = (t_vertices *)ft_memalloc(graph.max_size *
			sizeof(t_vertices))) || parse_lines(&graph, &graph.ret.map)
			== FAILURE)
		return (graph.ret);
	graph.ret.v_source = hm_find(graph.ret.map, graph.ret.source);
	graph.ret.v_sink = hm_find(graph.ret.map, graph.ret.sink);
	free((void *)graph.vertices);
	return (graph.ret);
}