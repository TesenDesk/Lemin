/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sbfs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:19:13 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:54 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

void			reset_queue(t_ddeq *hub, t_vertex *start)
{
	ft_ddeqpush_b_all(hub);
	ft_ddeq_new_a(&hub, start, sizeof(t_vertex *));
}

void			add_to_q_around(t_ddeq **hub, t_vertex *c, int att)
{
	t_dlist		*l;
	t_dlist		*head;

	l = c->links;
	head = l;
	if (c->visited < att)
		c->visited = att;
	while (l)
	{
		if (((t_vertex *)l->content)->visited < att &&
			!((t_vertex *)l->content)->cap)
		{
			ft_ddeq_new_a(hub, l->content, sizeof(t_vertex *));
			((t_vertex *)(*hub)->a->prev->content)->visited = att;
			((t_vertex *)(*hub)->a->prev->content)->parent = c;
		}
		l = l->next;
		if (head == l)
			break ;
	}
}

int				search_next_visited(t_vertex *c)
{
	int			res;
	t_dlist		*l;
	t_dlist		*h;

	res = 0;
	l = c->links;
	h = l;
	while (l)
	{
		if (((t_vertex *)l->content)->visited > res)
			res = ((t_vertex *)l->content)->visited;
		l = l->next;
		if (h == l)
			break ;
	}
	return (res + 1);
}

int				another_bfs(t_vertex *s, t_ddeq **hub)
{
	t_dlist		*q;
	int			vis_def;

	q = NULL;
	vis_def = search_next_visited(s);
	while (TRUE)
	{
		if (s->type != FIN && !(q && q == (*hub)->a))
		{
			if (s->parent)
				s->price = s->parent->price + 1;
			add_to_q_around(hub, s, vis_def);
			if (!q)
				q = (*hub)->a;
			if ((s = finish_found(s)))
				break ;
			q = q->next;
			s = q->content;
		}
		else
			break ;
	}
	if (s->type == FIN)
		return (TRUE);
	return (FALSE);
}

t_dlist			*add_another_path(t_vertex *s, t_vertex *f, t_ddeq *hub)
{
	t_dlist		*new_path;
	int			found;

	found = another_bfs(s, &hub);
	reset_queue(hub, s);
	if (!found || !(new_path = shortest_way(f)))
		return (NULL);
	lock_path(new_path);
	set_around_as_not_priced(f);
	return (new_path);
}
