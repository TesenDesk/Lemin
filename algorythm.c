/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:40:48 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/11 21:57:07 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void link_destroy(t_vertex *c, t_dlist *link)
{
	t_dlist	*current = NULL;

	current = c->links;
	while (current && current->next != link)
		current = current->next;
	if (current->next == link)
		current->next = link->next;
}

void solve_link(t_vertex *c, t_dlist *l)
{
	t_vertex *n;
	t_dlist *nl;

	n = l->content;
	nl = n->links;
	while (nl)
	{
		if (((t_vertex *)(nl->content))->price > n->price)
			link_destroy(c, l);
		nl = nl->next;
	}
}

void remove_useless_links(t_queu *q)
{
	t_dlist *l;
	t_vertex *c;

	c = q->current;
	q = q->next;
	while (c)
	{
		l = c->links;
		while (l)
		{
			if (c->price > ((t_vertex *)(l->content))->price)
				link_destroy(c, l);
			else if (c->price == ((t_vertex *)(l->content))->price)
				solve_link(c, l);
			l = l->next;
		}
		if (q)
		{
			c = q->current;
			q = q->next;
		}
		else
			c = NULL;
	}
}

void something(t_vertex *c) //TODO: Переименовать функцию :)
{
	t_queu *q;

	q = bfs(c); //TODO: функция поиска истока?
	remove_useless_links(q);
	//TODO: Дальнейший алгоритм :)
	queu_destroy(q);
}
