/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:40:48 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/06 19:53:11 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

int				run_deep_bfs(t_ddeq *hub, t_vertex *s, t_vertex *f)
{
	t_dlist		*new_path;

	if (deep_bfs(hub, s) && (new_path = deep_search_correct_path(f)))
	{
		lock_path(new_path);
		emergency_free_dlist(new_path);
	}
	else
		return (0);
	return (1);
}

t_dlist			*add_new_var(t_ddeq *hub, t_vertex **list, t_vertex *s,
					t_vertex *f)
{
	t_dlist		*new_path;
	t_dlist		*paths;
	t_dlist		*l;
	t_dlist		*h;

	paths = NULL;
	clear_all_prices(list, f);
	ft_ddeqreset_a(&hub, s);
	l = s->links;
	h = l;
	if (!run_deep_bfs(hub, s, f))
		return (NULL);
	while (TRUE)
	{
		if (l->flow == LOCKED)
			if ((new_path = lets_go(s, l->content)))
				ft_dlstpush_back(&paths, ft_dlstnew_ptr(new_path));
		l = l->next;
		if (l == h)
			break ;
	}
	return (paths);
}

t_dlist			*run_advanced_bfs(t_vertex *s, t_vertex *f, t_ddeq *hub,
						t_dlist *paths)
{
	t_dlist		*new_path;

	while ((new_path = add_another_path(s, f, hub)))
		ft_dlstpush_back(&paths, ft_dlstnew_ptr(new_path));
	return (paths);
}

t_dlist			*perform_deep_bfs_and_choose_best_ways(t_graph *g, t_ddeq *hub,
					t_dlist *paths)
{
	int			old_len;
	int			new_len;
	t_dlist		*old;

	old = paths;
	old_len = count_answer_len(paths, g->ret.ants_count);
	while ((paths = add_new_var(hub, g->vertices, g->ret.v_source,
						g->ret.v_sink)))
	{
		new_len = count_answer_len(paths, g->ret.ants_count);
		if (g->flags.d)
			debug_print_answer_len(new_len);
		ft_ddeqreset_a(&hub, g->ret.v_source);
		if (old_len <= new_len)
			paths_del(paths);
		else
		{
			old_len = new_len;
			paths_del(old);
			old = paths;
		}
	}
	return (old);
}

void			*algorithm_run(t_graph *g)
{
	t_dlist		*paths;
	t_ddeq		*hub;

	if (!(g->ret.v_source && g->ret.v_sink && g->vertices &&
				(hub = ft_ddeqnew(NULL))))
		return (NULL);
	if (!(paths = run_bfs(g->ret.v_source, g->ret.v_sink, hub)))
	{
		ft_ddeqdel(&hub, ft_delfunc_dummy);
		return (putstr_return_null("No Solution."));
	}
	paths = run_advanced_bfs(g->ret.v_source, g->ret.v_sink, hub, paths);
	count_answer_len(paths, g->ret.ants_count);
	debug_print_paths(paths, g, FALSE);
	paths = perform_deep_bfs_and_choose_best_ways(g, hub, paths);
	if (g->flags.d)
		print_line('*', 20);
	ft_ddeqdel(&hub, ft_delfunc_dummy);
	debug_print_paths(paths, g, TRUE);
	return (paths);
}
