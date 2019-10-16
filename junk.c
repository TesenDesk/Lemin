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
