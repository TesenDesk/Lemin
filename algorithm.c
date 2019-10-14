/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:40:48 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/14 23:10:41 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void lock_ways(t_vertex *c, t_vertex *d)
{
	t_dlist *l;

	l = c->links;
	while (l->content != d)
		l = l->next;
	l->flow = LOCKED;
	l = d->links;
	while (l->content != c)
		l = l->next;
	l->flow = VACUUM;
}

void lock_path(t_vertex *s, t_dlist *path)
{
	t_dlist *head;

	while (path)
	{
		lock_ways(s, path->next->content);
		path = path->next;
		if (path->next == head)
			break;
		s = path->content;
	}
}

t_vertex *find_cheap_vertex(t_vertex *c)
{
	t_vertex *res;
	t_dlist *l;
	t_dlist *head;

	res = c;
	l = c->links;
	head = l;
	while (l)
	{
		if (res->price > ((t_vertex *)(l->content))->price)
			res = l->content;
		l = l->next;
		if (l == head)
			break;
	}
	return (res);
}

t_dlist *shortest_way(t_vertex *f)
{
	t_dlist *path;
	t_dlist *l;
	t_dlist *head;

	path = ft_dlstnew(f, sizeof(void *)); //TODO: функция не подходит под задачу. нужно заменить.
	l = f->links->content;
	head = path;
	ft_dlstadd(&head, ft_dlstnew(find_cheap_vertex(f), sizeof(void *))); //todo: ect.
	while (((t_vertex *)(path->next->content))->type != START)
	{
		path = path->next;
		f = path->content;
		ft_dlstadd(&head, ft_dlstnew(f->parent, sizeof(void *))); //todo: ect...
	}
	return (l);
}

void something(t_vertex *s, t_vertex *f) //TODO: Переименовать функцию :)
{
	t_queu *q;
	t_dlist *path;

	q = bfs(s);
	path = shortest_way(f);
	lock_path(s, path);
	//TODO: Дальнейший алгоритм :)
	queu_destroy(q);
}


/* ************************************************************************** */
/* **************** OLD STAFF *********************************************** */
/* ************************************************************************** */


/*
** link_destroy уничтожает у вершины c связь link. **
*/

void link_destroy(t_vertex *c, t_dlist *link)
{t_dlist	*current = NULL;

	current = c->links;
	while (current && current->next != link)
		current = current->next;
	if (current && current->next == link)
		current->next = link->next;
}

/*
** solve_link разрешает проблему связей, у которых одинаковая стоимость. **
*/

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

/*
** remove_useless_links удалят все бесполезные соединения в посещенных **
** вершинах. Бесполезными считаются вершины, переход по которым **
** уменьшит стоимость. **
*/

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

/*
** remove_dead_links_here удаляет все связи с "мертвыми" вершинами, **
** в которые можно попасть из этой вершины c. Так же, если такое удаление **
** приводит к образованию нового тупика, он тоже будет удален. **
*/

void remove_dead_links_here(t_vertex *c)
{
	t_dlist *l;
	t_vertex *n;

	l = c->links;
	while (l)
	{
		n = l->content;
		if (!n->links)
		{
			link_destroy(c, l);
			if (!c->links)
				remove_dead_links_here(c->parent);
		}
	}
}

/*
** remove_dead_links применяет remove_dead_links_here к каждой посещенной **
** вершине на карте. Таким образом удалят все тупики. **
*/

void remove_dead_links(t_queu *q)
{
	t_vertex *c;

	c = q->current;
	while (c)
	{
		remove_dead_links_here(c);
		if (q)
		{
			c = q->current;
			q = q->next;
		}
		else
			c = NULL;
	}
}