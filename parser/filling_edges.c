/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_edges.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:20:26 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:25:49 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					allocate_links(t_edge *edge)
{
	int				state;

	state = FAILURE;
	if ((edge->links_l = ft_dlstnew_ptr(edge->vertex_r)) &&
			(edge->links_r = ft_dlstnew_ptr(edge->vertex_l)))
		state = SUCCESS;
	return (state);
}

int					v_cmp(const void *v_min, const void *v_sub)
{
	return (((t_dlist *)v_min)->content != v_sub);
}

int					check_dup_edges(t_edge *edge)
{
	t_vertex		*v_l;
	t_vertex		*v_r;

	v_l = edge->vertex_l;
	v_r = edge->vertex_r;
	if (v_l != v_r &&
			!ft_dlstfind(v_l->links, (void *)v_r, v_cmp) &&
			!ft_dlstfind(v_r->links, (void *)v_l, v_cmp))
		return (SUCCESS);
	else
		return (FAILURE);
}

void				put_edges(t_edge *edge)
{
	if (edge->vertex_l && edge->vertex_r)
	{
		ft_dlstpush_back(&edge->vertex_l->links, edge->links_l);
		ft_dlstpush_back(&edge->vertex_r->links, edge->links_r);
	}
	return ;
}

int					fill_edge(t_graph *graph)
{
	if (parse_vertices_names_and_allocate(graph) == FAILURE ||
			find_current_vertices(graph) == FAILURE ||
			allocate_links(&graph->edge) == FAILURE ||
			check_dup_edges(&graph->edge) == FAILURE)
		graph->reader.state = ERROR;
	else
		graph->reader.state = PARSE_EDGE;
	put_edges(&graph->edge);
	graph->edge.vertex_l = NULL;
	graph->edge.vertex_r = NULL;
	delete_auxiliary_vertices_names(&graph->edge.name_l, &graph->edge.name_r);
	return (graph->reader.state);
}
