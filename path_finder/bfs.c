/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 23:08:33 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:38 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

t_dlist				*queu_add(t_dlist *q, t_vertex *c, t_vertex *parent)
{
	t_dlist			*head;

	head = q;
	c->parent = parent;
	c->visited = TRUE;
	if (c->type != START && c->type != FIN)
		c->price = parent->price + 1;
	if (!(q = ft_dlstnew_ptr((void *)c)))
		emergency_free_dlist(head);
	ft_dlstpush_back(&head, q);
	return (head);
}

t_dlist				*add_this_q(t_vertex *c, t_dlist *q)
{
	t_dlist			*conn;
	t_dlist			*head;

	conn = c->links;
	head = conn;
	while (conn)
	{
		if (!(((t_vertex *)(conn->content))->visited))
			q = queu_add(q, conn->content, c);
		conn = conn->next;
		if (conn == head)
			break ;
	}
	return (q);
}

t_vertex			*finish_found(t_vertex *c)
{
	t_dlist			*l;
	t_dlist			*head;

	l = c->links;
	head = l;
	while (l)
	{
		if (((t_vertex *)(l->content))->type == FIN)
			return (l->content);
		l = l->next;
		if (l == head)
			break ;
	}
	return (NULL);
}

t_dlist				*bfs(t_vertex *c)
{
	t_dlist			*q;
	t_dlist			*qd;

	qd = NULL;
	c->visited = TRUE;
	qd = add_this_q(c, qd);
	q = qd;
	c = q->content;
	while (TRUE)
	{
		if (c->type != FIN)
		{
			add_this_q(c, qd);
			if ((q = q->next) == qd || finish_found(c))
				break ;
			c = q->content;
		}
		else
			break ;
	}
	return (qd);
}
