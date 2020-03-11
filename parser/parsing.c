/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:03:15 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:35:18 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					parse_ants(t_read *reader)
{
	reader->state = FILL_ANTS;
	return (reader->state);
}

int					parse_normal(t_read *reader)
{
	char			*str;
	int				type;

	str = reader->line;
	if (is_comment(str))
	{
		if ((type = is_dst_src(str)))
		{
			reader->type = type;
			return ((reader->state = SKIP_FOR_DSTSRC));
		}
		else
			return ((reader->state = SKIP_NORM_FILL));
	}
	else if (!is_vertex(str))
		return (reader->state = CREATE_MAP);
	return (reader->state = FILL_VERTEX);
}

int					rough_parse_vertex(t_read *reader)
{
	char			*str;

	str = reader->line;
	if (is_comment(str))
	{
		if (is_dst_src(str))
			return ((reader->state = PARSE_ERROR));
		else
			return ((reader->state = SKIP_FOR_DSTSRC));
	}
	if (!is_vertex(str))
		return ((reader->state = PARSE_ERROR));
	return ((reader->state = FILL_VERTEX));
}

int					rough_parse_edge(t_read *reader)
{
	if (*reader->line == '#')
		reader->state = SKIP_FOR_EDGE;
	else
		reader->state = FILL_EDGE;
	return (reader->state);
}
