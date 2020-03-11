/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:58:06 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:57 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

t_dlist			*shortest_way(t_vertex *f)
{
	t_dlist		*path;
	t_dlist		*tmp;

	if (!f)
		return (NULL);
	if (!(path = ft_dlstnew_ptr(f)))
		return (emergency_free_dlist(path));
	f = find_cheap_vertex(f);
	if (!f || !(tmp = ft_dlstnew_ptr(f)))
		return (emergency_free_dlist(path));
	ft_dlstpush(&path, tmp);
	while (((t_vertex *)(path->content))->type != START)
	{
		f = path->content;
		if (!(tmp = ft_dlstnew_ptr(f->parent)))
			return (emergency_free_dlist(path));
		ft_dlstpush(&path, tmp);
	}
	return (path);
}

void			set_around_as_not_priced(t_vertex *f)
{
	t_dlist		*l;
	t_dlist		*head;

	l = f->links;
	head = l;
	while (l)
	{
		((t_vertex *)(l->content))->price = -1;
		l = l->next;
		if (l == head)
			break ;
	}
}

void			lock_ways(t_vertex *c, t_vertex *d)
{
	t_dlist		*l;

	l = c->links;
	while (l->content != d)
		l = l->next;
	if (!l->flow)
		l->flow = LOCKED;
	else
		l->flow = OPEN;
	l = d->links;
	while (l->content != c)
		l = l->next;
	if (!l->flow)
		l->flow = VACUUM;
	else
		l->flow = OPEN;
}

void			lock_path(t_dlist *path)
{
	t_vertex	*s;

	s = path->content;
	while (1)
	{
		if (s->type != START)
		{
			if (s->type != FIN)
				s->cap = 1;
			else
				break ;
		}
		path = path->next;
		lock_ways(s, path->content);
		s = path->content;
	}
}

t_vertex		*find_cheap_vertex(t_vertex *f)
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
		if (res->price > ((t_vertex *)(l->content))->price
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
