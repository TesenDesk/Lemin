/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_addons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:32:59 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:42 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

void			clear_all_prices(t_vertex **list, t_vertex *f)
{
	int			i;

	i = -1;
	while (list[++i])
		list[i]->price = -1;
	f->price = INT_MAX;
}

t_vertex		*deep_find_cheap_link(t_vertex *f)
{
	t_vertex	*res;
	t_dlist		*l;
	t_dlist		*head;

	if (!f || !f->links)
		return (NULL);
	res = f;
	head = f->links;
	l = f->links;
	while (TRUE)
	{
		if (l->flow == OPEN && res->price > ((t_vertex *)(l->content))->price
			&& ((t_vertex *)(l->content))->price >= 0)
			res = l->content;
		l = l->next;
		if (l == head)
			break ;
	}
	if (res == f)
		return (NULL);
	return (res);
}

t_dlist			*deep_search_correct_path(t_vertex *f)
{
	t_dlist		*path;
	t_vertex	*v;
	t_dlist		*tmp;

	v = deep_find_cheap_link(f);
	if (!v)
		return (NULL);
	if (!(path = ft_dlstnew_ptr(f)))
		return (emergency_free_dlist(path));
	while (v->type != START)
	{
		if (!(tmp = ft_dlstnew_ptr(v)))
			return (emergency_free_dlist(path));
		ft_dlstpush(&path, tmp);
		if (!v->parent)
			return (emergency_free_dlist(path));
		v = v->parent;
	}
	if (!(tmp = ft_dlstnew_ptr(v)))
		return (emergency_free_dlist(path));
	ft_dlstpush(&path, tmp);
	return (path);
}

t_dlist			*search_locked_way(t_vertex *v)
{
	t_dlist		*l;
	t_dlist		*h;

	l = v->links;
	h = l;
	while (TRUE)
	{
		if (l->flow == LOCKED)
			return (l);
		l = l->next;
		if (h == l)
			break ;
	}
	return (NULL);
}

t_dlist			*lets_go(t_vertex *s, t_vertex *v)
{
	t_dlist		*path;
	t_dlist		*l;

	path = ft_dlstnew_ptr(s);
	ft_dlstpush_back(&path, ft_dlstnew_ptr(v));
	if ((l = search_locked_way(v)))
		v = l->content;
	while (v->type != FIN)
	{
		ft_dlstpush_back(&path, ft_dlstnew_ptr(v));
		if ((l = search_locked_way(v)))
			v = l->content;
		else
			return (emergency_free_dlist(path));
	}
	ft_dlstpush_back(&path, ft_dlstnew_ptr(v));
	return (path);
}
