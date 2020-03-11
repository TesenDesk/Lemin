/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:15:37 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:16:54 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

void			count_paths_length(t_dlist *paths)
{
	t_dlist		*curr;
	t_dlist		*path;

	path = paths;
	while (TRUE)
	{
		curr = (t_dlist *)path->content;
		path->flow = ft_dlstsize(curr) - 2;
		if ((path = path->next) == paths)
			break ;
	}
	return ;
}

int				check_input_and_initialize(t_lines *properties, t_dlist *paths,
					int charge)
{
	if (!paths || !paths->content || !properties)
		return (FAILURE);
	properties->charge = charge;
	count_paths_length(paths);
	ft_dlstsort_bubble(paths);
	properties->min_len = paths->flow;
	properties->paths = paths;
	properties->path_curr = paths;
	return (SUCCESS);
}

int				check_special_case(t_lines *properties, t_dlist *paths)
{
	if (!properties->charge)
		return (0);
	else if (!properties->min_len)
		return (1);
	else if (paths->next == paths)
		return (properties->min_len + properties->charge);
	return (FAILURE);
}

int				count_answer_len(t_dlist *paths, int charge)
{
	t_lines		properties;
	int			len;

	ft_bzero((void *)&properties, sizeof(properties));
	if (check_input_and_initialize(&properties, paths, charge))
		return (FAILURE);
	if ((len = check_special_case(&properties, paths)) != FAILURE)
		return (len);
	len = count_steps(&properties) + properties.min_len;
	return (len);
}
