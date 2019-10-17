/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:40:48 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/17 12:39:10 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin_my.h"

/*
** lock_ways выставляет параметры связей между c и d. **
** Устанавливает в сторону c->d значение потока LOCKED, **
** в обратную сторону - VACUUM. **
** Внимание! Не хватило строк на защиту от беск. циклов. **
** Две поданные вершины ОБЯЗАТЕЛЬНО должны быть связаны между собой! **
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
** устанавливает в сторну потока параметр связи LOCKED, **
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
		if (s->type != FIN)
			s->cap = 1;
		path = path->next;
		lock_ways(s, path->content);
		if (path == head)
			break ;
		s = path->content;
	}
}

/*
** find_cheap_vertex ищет вершину, которая соеденена с вершиной c и **
** имеет наименьшую стоимость. **
*/

t_vertex *find_cheap_vertex(t_vertex *c)
{
	t_vertex *res;
	t_dlist *l;
	t_dlist *head;

	if (!c)
		return (NULL);
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

/*
** do_nothing - самая полезная функция в проекте. **
** Делает ̶а̶х̶у очень крутые вещи. **
*/

void do_nothing(void *nothing, size_t size)
{
	(void)nothing;
	(void)size;
}

/*
** emergency_free_dlist очищает список t_dlist и возвращает NULL **
** Внимание! Не очищает содержимое content, только сам список **
*/

void *emergency_free_dlist(t_dlist *path)
{
	ft_dlstdel(&path, do_nothing);
	return (NULL);
}

/*
** shortest_way ищет наикротчайший путь до стока. **
** требуется указать на сток. **
** Возвращает структуру t_dlist, в которой записан путь. **
*/

t_dlist *shortest_way(t_vertex *f)
{
	t_dlist *path;
	t_dlist *head;
	t_dlist *tmp;

	if (!f)
		return (NULL);
	if (!(path = ft_dlstnew(&f, sizeof(t_vertex *))))
		return (emergency_free_dlist(path));
	head = path;
	f = find_cheap_vertex(f);
	if (!(tmp = ft_dlstnew(&f, sizeof(t_vertex *))))
		return (emergency_free_dlist(path));
	ft_dlstpush_back(&head, tmp);
	while (((t_vertex *)(path->next->content))->type != START)
	{
		path = path->next;
		f = path->content;
		if (!(tmp = ft_dlstnew(&f->parent, sizeof(t_vertex *))))
			return (emergency_free_dlist(path));
		ft_dlstpush_back(&head, tmp);
	}
	return (path);
}

/*
** set_around_as_not_visited устанавливет во всех связанных вершинах **
** счетчик visited в -1. **
*/

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

void add_this_to_queue_deep(t_vertex *c, t_ddeq *hub, int flow, int att)
{
	if (c->visited == att)
		return ;
	ft_ddeq_new_a(&hub, (void *)&c, sizeof(t_vertex *));
	hub->a->prev->flow = flow;
}

void add_all_in_link_to_q(t_ddeq *hub, t_dlist *link, int attempt)
{
	t_dlist *head;
	t_dlist *l;
	t_vertex *c;

	c = link->content;
	l = c->links;
	head = l;
	while (l)
	{
		if (l->flow == VACUUM)
			add_this_to_queue_deep(l->content, hub, l->flow, attempt);
		else if (l->flow == OPEN)
			if (!c->cap || link->flow == VACUUM)
				add_this_to_queue_deep(l->content, hub, l->flow, attempt);
	}
}

void check_all_links_at_this(t_ddeq *hub, t_dlist *q, int att, t_vertex *p)
{
	t_dlist *l;
	t_dlist *h;

	l = ((t_vertex *)(q->content))->links;
	h = l;
	while (l)
	{
		if (l->flow == VACUUM || (l->flow == OPEN && q->flow == OPEN))
			add_all_in_link_to_q(hub, l, att);
		l = l->next;
		if (l == h)
			break ;
	}
	((t_vertex *)(q->content))->visited = att;
	((t_vertex *)(q->content))->parent = p;
}

void add_q_at_start(t_ddeq *hub, int attempt)
{
	t_dlist *l;
	t_dlist *head;
	t_vertex *s;

	s = (t_vertex *)hub->a->content;
	l = s->links;
	head = l;
	s->visited = attempt;
	while (l)
	{
		if (l->flow == OPEN)
			add_this_to_queue_deep(l->content, hub, OPEN, attempt);
		l = l->next;
		if (l == head)
			break ;
	}
}

t_dlist *make_q_deep(t_ddeq *hub, int att)
{
	t_dlist *h;
	t_dlist *q;
	//t_dlist *l;
	t_vertex *parent;

	q = hub->a;
	h = q;
	add_q_at_start(hub, att);
	while (q)
	{
		parent = q->content;
		q = q->next;
		if (q == h)
			break ;
		check_all_links_at_this(hub, q, att, parent);
	}
	return (q);
}

void *something(t_vertex *s, t_vertex *f) //TODO: Переименовать функцию :)
{
	//t_dlist *variants;
	t_dlist *paths;
	t_dlist *new_path;
	t_ddeq *hub;
	int i;

	i = 1;
	hub = ft_ddeqnew(NULL);
	hub->b = bfs(s);
	if (!(paths = ft_dlstnew(NULL, 0)))
		return (NULL);
	paths->content = shortest_way(f);//todo: найти доп. не пересекающиеся пути
	lock_path(paths->content);
	ft_ddeq_new_a(&hub, s, sizeof(t_vertex *));
	new_path = make_q_deep(hub, ++i);
	return (paths);
}

/* ************************************************************************** */
/* **************** OLD STAFF *********************************************** */
/* ************************************************************************** */
