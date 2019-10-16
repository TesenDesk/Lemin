/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:50:49 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 23:10:07 by jjerde           ###   ########.fr       */
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
	// Осовобождение списков смежности не реализовано.
	ft_free_ptr_ar((void ***)(&graph->vertices));
		ft_memdel((void **)line);
	(void)map;
//	hm_del(map);
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
			put_edges(&line, map);
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
	t_hash_map		*map;

	graph.max_size = BEST_SIZE > 0 ? BEST_SIZE : 4096;
	map = NULL;
	if (!(graph.vertices = (t_vertices *)ft_memalloc(graph.max_size *
			sizeof(t_vertices))) || parse_lines(&graph, &map)
			== FAILURE)
		return (graph.ret);
	free((void *)graph.vertices);
	return (graph.ret);
}