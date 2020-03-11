/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ants_and_nbr_field.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:03:18 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:21:13 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					fill_nbr_field_if_possible(char *str, int len, int *field)
{
	if (!ft_isdigitnstr(str, len) ||
			ft_strint_ou_flow(str, field) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int					fill_ants(t_graph *graph)
{
	char			*str;

	str = graph->reader.line;
	if (fill_nbr_field_if_possible(str, ft_strlen(str), &graph->ret.ants_count)
			== FAILURE ||
			graph->ret.ants_count <= 0)
		graph->reader.state = ERROR;
	else
		graph->reader.state = PARSE_NORMAL;
	return (graph->reader.state);
}
