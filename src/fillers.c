/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:05:12 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/17 16:40:52 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

void				emergency_free_edge_setter(t_edge *edge)
{
	free((void *)edge->name_l);
	free((void *)edge->name_r);
	free((void *)edge->dlist_l);
	free((void *)edge->dlist_r);
	return ;
}

int					set_names(char **line, t_edge *edge)
{
	char			*temp;

	temp = ft_strchr(*line, '-');
	edge->name_l = ft_strsub(*line, 0, temp - *line);
	++temp;
	if (edge->name_l)
		edge->name_r = ft_strsub(temp, 0, ft_strlen(temp));
	if (!edge->name_r)
		ft_memdel((void **)&edge->name_l);
	ft_memdel((void **)line);
	return (!edge->name_l ? FAILURE : SUCCESS);
}

int					set_vertices(t_edge *edge, t_hash_map **map)
{
	edge->vertex_l = find_vertex(*map, edge->name_l);
	if (edge->vertex_l)
		edge->vertex_r = find_vertex(*map, edge->name_r);
	return (!edge->vertex_l ? FAILURE : SUCCESS);
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

int					set_edges(char **line, t_hash_map **map, t_edge *edge)
{
	if (set_names(line, edge) || set_vertices(edge, map) ||
			!(edge->dlist_l = ft_dlstnew((void const *)(&edge->vertex_r),
				sizeof(t_vertex))) ||
			!(edge->dlist_r = ft_dlstnew((void const *)(&edge->vertex_l),
				sizeof(t_vertex))) ||
			check_dup_edges(edge))
	{
		emergency_free_edge_setter(edge);
		return (FAILURE);
	}
	free((void *)edge->name_l);
	free((void *)edge->name_r);
	return (SUCCESS);
}

int					put_edges(char **line, t_hash_map **map)
{
	t_edge			edge;

	ft_bzero((void *)&edge, sizeof(edge));
	if (set_edges(line, map, &edge))
		return (FAILURE);
	ft_dlstpush_back(&edge.vertex_l->links, edge.dlist_l);
	ft_dlstpush_back(&edge.vertex_r->links, edge.dlist_r);
	return (SUCCESS);
}

int					fill_map_with_vertices(t_graph *graph, char **line,
		int *state, t_hash_map **map)
{
	int				v_size;
	t_vertex		*vertex;
	t_vertices		*vertices;

	v_size = graph->v_size;
	vertices = graph->vertices;
	while (v_size)
	{
		if (!(vertex = vertex_new(graph, --v_size)))
		{
			*state = ERROR;
			break ;
		}
		hm_put(map, (void *)(vertices + v_size)->name, (void *)vertex);
	}
	*state = (put_edges(line, map) == FAILURE) ? ERROR : *state;
	return (*state == ERROR ? FAILURE : SUCCESS);
}

void				set_type_and_price(t_graph *graph, t_vertices *v_curr)
{	
	if (v_curr->type == SINK)
	{
		graph->ret.sink = v_curr->name;
		v_curr->price = INT_MAX;
	}
	else if (v_curr->type == SOURCE) 
	{
		graph->ret.source = v_curr->name;
		v_curr->price = 0;
	}
	else
		v_curr->price = -1;
	return ;
}

void				fill_vertex(t_graph *graph, char **line, int *state)
{
	char			*top;
	t_vertices		*v_curr;

	if (graph->v_size == graph->max_size)
		if (resize_vertices(graph, state) == FAILURE)
			return ;
	v_curr = graph->vertices + graph->v_size;
	if (!(top = ft_strchr(*line, ' ')) ||
			!(v_curr->name = ft_strsub(*line, 0, top - *line)))
	{
		*state = ERROR;
		return ;
	}
	set_type_and_price(graph, v_curr);
	++graph->v_size;
 	ft_memdel((void **)line);
	return ;
}