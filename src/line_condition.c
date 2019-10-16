/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:57:37 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/15 17:53:36 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					iscomment(char *str)
{
	return (*str == '#');
}

int					isvertex(char *str)
{
	return (!ft_strchr(str, '-') && ft_strchr(str, ' '));
}

int					is_edge(char *str)
{
	return (!!ft_strchr(str, '-'));
}

int					try_dst_src(t_graph *graph, char **line)
{
	int				state;
	char *str;

	str = *line;
	state = FALSE;
	if ((state = !ft_strcmp(str, "##start")) || !ft_strcmp(str, "##end"))
	{
		graph->vertices[graph->v_size].type = state ? SOURCE : SINK;
		state = WAIT_VERTEX;
	}
	else
		state = NORMAL;
	ft_memdel((void **)line);
	return (state);
}