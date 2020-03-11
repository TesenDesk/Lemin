/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:46:50 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 16:43:29 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int						get_map_from_file(t_read *reader, char *file)
{
	if (!file || (reader->fd = open(file, O_RDONLY)) < SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int						catch_flags2(const char *str, t_graph *graph, int i)
{
	if (str[i] == 'c')
		graph->flags.c = 1;
	else if (str[i] == 'd')
		graph->flags.d = 1;
	else if (str[i] == 'f')
		graph->flags.f = 1;
	else
	{
		graph->flags.u = 1;
		return (0);
	}
	return (1);
}

int						catch_flags(const char *str, t_graph *graph)
{
	int			i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == '-')
			continue ;
		else if (str[i] == 'h')
		{
			graph->flags.h = 1;
			return (0);
		}
		else if (str[i] == 'p')
			graph->flags.p = 1;
		else if (str[i] == 'n')
			graph->flags.n = 1;
		else if (str[i] == 'l')
			graph->flags.l = 1;
		else if (str[i] == 'k')
			graph->flags.k = 1;
		else if (!catch_flags2(str, graph, i))
			return (0);
	}
	return (1);
}
