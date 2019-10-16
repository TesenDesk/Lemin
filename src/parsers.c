/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:06:34 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/15 17:53:19 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					parse_nbr(t_graph *graph, char **line)
{
	char			*str;
	int				state;

	state = NORMAL;
	str = *line;
	if (!(ft_isdigitstr(str)) ||
		ft_strint_ou_flow(str, &graph->ret.ants_count) == FAILURE ||
			graph->ret.ants_count <= 0)
		state = ERROR;
	ft_memdel((void **)line);
	return (state);
}

int					parse_vertex(t_graph *graph, char **line)
{
	// char			*str;
	int				state;

	state = ERROR;
	if ((state = iscomment(*line) ? WAIT_VERTEX : state) == WAIT_VERTEX)
		ft_memdel((void **)line);
	else if ((state = isvertex(*line) ? NORMAL : state) == NORMAL)
		fill_vertex(graph, line, &state);
	return (state);
}

int					parse_normal(t_graph *graph, char **line)
{
//	char			*str;
	int				state;

	state = ERROR;
	if (iscomment(*line))
		state = try_dst_src(graph, line);
	else if (isvertex(*line))
	{
		state = NORMAL;
		fill_vertex(graph, line, &state);
	}
	else if (is_edge(*line) && graph->v_size)
		state = WAIT_EDGE;
	return (state);
}

t_parse				*parse_dispatcher(int state)
{
	static t_parse	ar[] = {parse_normal, parse_nbr, parse_vertex};

	return (ar + state);
}

