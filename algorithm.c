/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:40:48 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/15 23:20:27 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** lock_ways выставляет параметры связей между c и d. **
** Устанавливает в сторону c->d значение потока LOCKED, **
** в обратную сторону - VACUUM. **
*/

void lock_ways(t_vertex *c, t_vertex *d)
{
	t_dlist *l;

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

/*
** lock_path регулирует параметры всех связей по пути path. **
** устанавливает в стороу потока параметр связи LOCKED, **
** в обратную - VACUUM. **
*/

void lock_path(t_dlist *path)
{
	t_dlist *head;
	t_vertex *s;

	head = path;
	s = path->content;
	while (1)
	{
		lock_ways(s, path->next->content);
		path = path->next;
		if (path == head)
			break ;
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
	while (1)
	{
		if (res->price != -1 && res->price > ((t_vertex *)(l->content))->price)
			res = l->content;
		l = l->next;
		if (l == head)
			break ;
	}
	return (res);
}

void do_nothing(void *nothing, size_t size)
{
	(void)nothing;
	(void)size;
}

void *free_path(t_dlist *path)
{
	ft_dlstdel(&path, do_nothing);
	return (NULL);
}

t_dlist *shortest_way(t_vertex *f)
{
	t_dlist *path;
	t_dlist *head;
	t_dlist *tmp;

	if (!(path = ft_dlstnew(&f, sizeof(t_vertex *))))
		return (free_path(path));
	head = path;
	f = find_cheap_vertex(f);
	if (!(tmp = ft_dlstnew(&f, sizeof(t_vertex *))))
		return (free_path(path));
	ft_dlstpush_back(&head, tmp);
	while (((t_vertex *)(path->next->content))->type != START)
	{
		path = path->next;
		f = path->content;
		if (!(tmp = ft_dlstnew(&f->parent, sizeof(t_vertex *))))
			return (free_path(path));
		ft_dlstpush_back(&head, tmp);
	}
	return (path);
}

void set_around_as_not_visited(t_vertex *f)
{
	t_dlist *l;
	t_dlist *head;

	l = f->links;
	head = l;
	while (l)
	{
		((t_vertex *)(l ->content))->price = -1;
		l = l->next;
		if (l->next == head)
			break ;
	}
}

void add_queue_deep(t_vertex *c, t_dlist *q, int attempt)
{
	q->prev->content = c;
	c->visited = attempt;
}

void add_all_to_queue_deep(t_vertex *c, t_dlist *q, int attempt)
{
	t_dlist *l;
	t_dlist *head;

	l = c->links;
	while (l)
	{
		if (l->flow == OPEN)//todo: разобраться с формулой!.
		{
			if (((t_vertex *) (l->content))->visited < attempt && )
				add_queue_deep(l->content, head, attempt);
		}
		l = l->next;
		if (l == head)
			break ;
	}
}

void *bfs_deep(t_vertex *s, int attempt)
{
	t_vertex *current;
	t_dlist *q;

	q->content =
}

void *something(t_vertex *s, t_vertex *f) //TODO: Переименовать функцию :)
{
	t_queu *q;
	t_dlist *paths;
	t_dlist *new_path;

	q = bfs(s);
	if (!(paths = ft_dlstnew(NULL, 0)))
		return (NULL);
	paths->content = shortest_way(f);//todo: найти доп. не пересекающиеся пути
	lock_path(paths->content);
	while ((new_path = bfs_deep(s)))
	{

	}

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