/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staff_for_bfs_and_other.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 00:20:05 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/06 00:20:08 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

t_dlist	*run_bfs(t_vertex *s, t_vertex *f, t_ddeq *hub)
{
	t_dlist		*paths;
	t_dlist		*new_path;

	hub->b = bfs(s);
	if (!(new_path = shortest_way(f)))
		return (NULL);
	if (!(paths = ft_dlstnew_ptr(new_path)))
		return (emergency_free_dlist(new_path));
	lock_path(paths->content);
	set_around_as_not_priced(f);
	ft_ddeq_new_a(&hub, s, sizeof(t_vertex *));
	return (paths);
}

void	debug_print_amount_of_paths(t_dlist *paths)
{
	print_line('=', 10);
	ft_putstr("Paths found: ");
	ft_putnbr(ft_dlstsize(paths));
	write(1, "\n", 1);
	print_line('=', 10);
}
