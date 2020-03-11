/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_addons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:09:01 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:51 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

t_dlist		*search_flow_parent(t_vertex *from, t_vertex *to, int i)
{
	t_dlist		*l;
	t_dlist		*h;

	l = to->links;
	h = l;
	while (TRUE)
	{
		if (l->flow == VACUUM && from->parent != to)
		{
			to->parent = from;
			to->visited = i;
			to->price = from->price + 1;
			return (l);
		}
		l = l->next;
		if (l == h)
			break ;
	}
	return (NULL);
}

void		remove_visited(t_dlist *hq)
{
	t_dlist		*q;
	t_vertex	*v;

	q = hq;
	while (TRUE)
	{
		v = q->content;
		if (v->cap)
			v->visited = -1;
		if ((q = q->next) == hq)
			break ;
	}
}

void		set_params(t_vertex *v, t_vertex *p, int i)
{
	v->parent = p;
	v->price = p->price + 1;
	v->visited = i;
}
