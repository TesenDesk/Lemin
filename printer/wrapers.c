/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:36:44 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:38:22 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

t_dlist			*a_path(t_dlist *paths)
{
	t_dlist		*path;

	path = (t_dlist *)paths->content;
	return (path);
}

t_vertex		*a_vertex(t_dlist *path)
{
	t_vertex	*vertex;

	vertex = (t_vertex *)path->content;
	return (vertex);
}
