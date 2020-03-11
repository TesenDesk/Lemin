/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_research.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:31:33 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:52 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

int			r_add_to_q(t_dlist *hq, t_dlist *l, int i, t_vertex *p)
{
	t_vertex	*added;

	added = l->content;
	if (added->type == FIN)
		return (TRUE);
	ft_dlstpush_back(&hq, ft_dlstnew_ptr(added));
	hq->prev->flow = l->flow;
	added->visited = i;
	added->parent = p;
	added->price = added->parent->price + 1;
	return (FALSE);
}

int			r_think_about(t_dlist *hq, t_dlist *q, t_dlist *l, int i)
{
	t_vertex	*v;

	v = l->content;
	if (v->type == START)
		return (FALSE);
	if (l->flow == VACUUM)
	{
		if (r_add_to_q(hq, l, i, q->content))
			return (TRUE);
	}
	else if (l->flow == OPEN)
	{
		if ((q->flow == OPEN && !v->cap) || q->flow == VACUUM)
			if (r_add_to_q(hq, l, i, q->content))
				return (TRUE);
	}
	return (FALSE);
}

int			r_add_around(t_dlist *hq, t_vertex *v, int i, t_dlist *q)
{
	t_dlist		*l;
	t_dlist		*h;
	t_vertex	*look;

	l = v->links;
	h = l;
	while (TRUE)
	{
		look = l->content;
		if (look->visited != i)
		{
			if (look->cap && l->flow == OPEN)
			{
				if (recursive_q(look, i, v))
					return (TRUE);
			}
			else if (r_think_about(hq, q, l, i))
				return (TRUE);
		}
		if ((l = l->next) == h)
			break ;
	}
	return (FALSE);
}

int			recursive_q(t_vertex *to, int i, t_vertex *from)
{
	t_dlist		*q;
	t_dlist		*hq;
	t_vertex	*v;
	t_dlist		*l;

	l = search_flow_parent(from, to, i);
	if (!l || !(v = l->content) || v->visited == i)
		return (FALSE);
	set_params(v, to, i);
	q = NULL;
	ft_dlstpush_back(&q, ft_dlstnew_ptr(to));
	r_add_to_q(q, l, i, to);
	q->flow = OPEN;
	hq = q;
	q = q->next;
	while (TRUE)
	{
		if (r_add_around(hq, v, i, q))
			return (emergency_free_dlist_return_int(hq, TRUE));
		if ((q = q->next) == hq)
			break ;
		v = q->content;
	}
	remove_visited(hq);
	return (emergency_free_dlist_return_int(hq, FALSE));
}
