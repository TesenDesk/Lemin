/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_research.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:27:55 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:44 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

int				deep_add_this_to_q(t_ddeq *hub, t_dlist *l, int i, t_vertex *p)
{
	t_vertex	*new;

	new = l->content;
	if (new->type == FIN)
		return (TRUE);
	ft_ddeq_new_a(&hub, new, sizeof(void *));
	hub->a->prev->flow = l->flow;
	if (!new->cap)
		new->visited = i;
	new->parent = p;
	new->price = new->parent->price + 1;
	return (FALSE);
}

int				think_about(t_ddeq *hub, t_dlist *q, t_dlist *l, int att)
{
	t_vertex	*v;

	v = q->content;
	if (l->flow == VACUUM)
	{
		if (deep_add_this_to_q(hub, l, att, v))
			return (TRUE);
	}
	else if (l->flow == OPEN)
	{
		if ((q->flow == OPEN && !v->cap) || q->flow == VACUUM)
			if (deep_add_this_to_q(hub, l, att, v))
				return (TRUE);
	}
	return (FALSE);
}

int				deep_add_around_start(t_ddeq *hub, t_vertex *start, int att)
{
	t_dlist		*l;
	t_dlist		*h;

	l = start->links;
	h = l;
	while (TRUE)
	{
		if (l->flow == OPEN)
			if (deep_add_this_to_q(hub, l, att, start))
				return (TRUE);
		l = l->next;
		if (l == h)
			break ;
	}
	return (FALSE);
}

int				deep_add_around_this(t_ddeq *hub, t_vertex *s, int i,
									t_dlist *q)
{
	t_dlist		*l;
	t_dlist		*h;
	t_vertex	*look;

	l = s->links;
	h = l;
	while (TRUE)
	{
		look = l->content;
		if (look->type != START)
		{
			if (look->cap && l->flow == OPEN && recursive_q(look, i, s))
				return (TRUE);
			else if (look->visited < i)
				if (think_about(hub, q, l, i))
					return (TRUE);
		}
		if ((l = l->next) == h)
			break ;
	}
	return (FALSE);
}

int				deep_bfs(t_ddeq *hub, t_vertex *s)
{
	t_dlist		*q;
	int			att;

	s->price = 0;
	att = search_next_visited(s);
	s->visited = att;
	if (deep_add_around_start(hub, s, att))
		return (TRUE);
	q = hub->a->next;
	s = q->content;
	while (TRUE)
	{
		if (deep_add_around_this(hub, s, att, q))
			return (TRUE);
		if ((q = q->next) == hub->a)
			break ;
		s = q->content;
	}
	return (FALSE);
}
