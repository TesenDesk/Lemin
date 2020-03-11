/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_errors_and_skips.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:36:13 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:19:50 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					error_before_filling(t_graph *graph)
{
	return (graph->reader.state = ERROR);
}

int					skip_filling(t_graph *graph)
{
	graph->reader.state = (graph->reader.state == SKIP_NORM_FILL) ?
			PARSE_NORMAL : PARSE_VERTEX;
	return (graph->reader.state);
}

int					skip_edge_filling(t_graph *graph)
{
	graph->reader.state = PARSE_EDGE;
	return (graph->reader.state);
}
