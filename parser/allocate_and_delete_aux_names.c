/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_and_delete_aux_names.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:26:22 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/25 18:34:53 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					parse_vertices_names_and_allocate(t_graph *graph)
{
	char			*name_l;
	char			*name_r;
	int				state;

	state = FAILURE;
	name_l = graph->reader.line;
	if ((name_r = ft_strchr(name_l, '-')))
		if ((graph->edge.name_l = ft_strsub(name_l, 0, name_r++ - name_l)))
			if ((graph->edge.name_r = ft_strdup(name_r)))
				state = SUCCESS;
	return (state);
}

void				delete_auxiliary_vertices_names(char **name_l,
						char **name_r)
{
	ft_memdel((void **)name_l);
	ft_memdel((void **)name_r);
	return ;
}
