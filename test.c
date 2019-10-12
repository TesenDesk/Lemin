/* ************************************************************************** */
/* ****** This is a 42.fr header. Trust me. I am a dolphin. ***************** */
/* ************************************************************************** */

#include "lemin.h"

/*
** add_this_q добавляет в очередь q все вершины, которые соеденены **
** с данной вершиной c и не отмеченные как посещенные. **
** если очереди не существует, создает новую. **
** возвращает указатель на голову очереди. **
*/

t_queu *add_this_q(t_vertex *c, t_queu *q)
{
	t_dlist *conn;

	conn = c->links;
	while (conn)
	{
		if (((t_vertex *)(conn->content))->visited)
			conn = conn->next;
		else
			queu_add(q, conn->content);
	}
	return (q);
}

/*
** way_price исследует родителей вершин и определяет стоимость пути **
** от истока до вершины c. В случае подачи c = исток, вернет 0. **
** В случае ошибки (нет родителя или точка не была посещена) вернет -1. **
** Функция не защищена от беск. циклов! Родители не должны повторяться! **
** NOTE: Нужно подавать заполненную структуру данных (после bhs, например) **
** NOTE: Не может корректно определить стоимость пути до стока, т.к. у **
** него может быть несколько родителей. **
** В таком случае необходимо указывать вершины, соедененные со стоком. **
*/

int	way_price(t_vertex *c)
{
	int i;

	i = 0;
	if (!c)
		return (-1);
	while (c->type != START)
	{
		if (!c->visited && !c->parent)
			return (-1);
		c = c->parent;
		++i;
	}
	return (i);
}

/*
** применяет алгоритм поиска в ширину. Требует указатель на стартовую **
** вершину c (исток). Записывает в поле parent сведения о родителе. **
** В поле price записывает стоимость пути до этой вершины от стока. **
*/

int finish_found(t_vertex *c)
{
	t_dlist	*l;

	l = c->links;
	while (l)
	{
		if (((t_vertex *)(l->content))->type == 2)
			return (1);
		l = l->next;
	}
	return (0);
}


t_queu *bfs(t_vertex *c)
{
	t_vertex	*tmp = NULL;
	t_queu		*q = NULL;
	t_queu		*qd = NULL;

	while (c)
	{
		c->parent = tmp;
		if (c->type != FIN)
			c->visited = TRUE;
		if (c->parent)
			c->price = c->parent->price + 1;
		else
			c->price = 0;
		q = add_this_q(c, q);
		qd = q;
		tmp = c;
		if (c->type == 2)
			c = NULL;
		else
			c = q->current;
		q = q->next;
	}
	return (qd);
}

/* ************************************************************************** */
/* ********* THIS IS THE DEBUG ZONE! DON'T FORGET DELETE THIS!!! ************ */
/* ************************************************************************** */
/*
t_map *create_map(void)
{
	t_map *map = ft_memalloc(sizeof(t_map));
	t_conn *con;

	map->start = ft_memalloc(sizeof(t_pair));
	map->a = ft_memalloc(sizeof(t_pair));
	map->b = ft_memalloc(sizeof(t_pair));
	map->c = ft_memalloc(sizeof(t_pair));
	map->d = ft_memalloc(sizeof(t_pair));
	map->e = ft_memalloc(sizeof(t_pair));
	map->f = ft_memalloc(sizeof(t_pair));
	map->g = ft_memalloc(sizeof(t_pair));
	map->h = ft_memalloc(sizeof(t_pair));
	map->finish = ft_memalloc(sizeof(t_pair));

	map->start->content = ft_memalloc(sizeof(t_vertex));
	map->a->content = ft_memalloc(sizeof(t_vertex));
	map->b->content = ft_memalloc(sizeof(t_vertex));
	map->c->content = ft_memalloc(sizeof(t_vertex));
	map->d->content = ft_memalloc(sizeof(t_vertex));
	map->e->content = ft_memalloc(sizeof(t_vertex));
	map->f->content = ft_memalloc(sizeof(t_vertex));
	map->g->content = ft_memalloc(sizeof(t_vertex));
	map->h->content = ft_memalloc(sizeof(t_vertex));
	map->finish->content = ft_memalloc(sizeof(t_vertex));

	map->start->key = "START";
	((t_vertex *)(map->start->content))->type = START;
	con = ft_memalloc(sizeof(t_conn));
	con->current = map->a;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->c;
	con->next = NULL;
	((t_vertex *)(map->start->content))->cons = con;

	map->a->key= "A";
	((t_vertex *)(map->a->content))->type = 0;
	con = ft_memalloc(sizeof(t_conn));
	con->current = map->b;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->start;
	con->next = NULL;
	((t_vertex *)(map->a->content))->cons = con;

	map->b->key = "B";
	((t_vertex *)(map->b->content))->type = 0;
	con = ft_memalloc(sizeof(t_conn));
	con->current = map->e;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->a;
	con->next = NULL;
	((t_vertex *)(map->b->content))->cons = con;

	map->c->key = "C";
	((t_vertex *)(map->c->content))->type = 0;
	con = ft_memalloc(sizeof(t_conn));
	con->current = map->d;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->start;
	con->next = NULL;
	((t_vertex *)(map->c->content))->cons = con;

	map->d->key = "D";
	((t_vertex *)(map->d->content))->type = 0;
	con = ft_memalloc(sizeof(t_conn));
	con->current = map->g;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->e;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->c;
	con->next = NULL;
	((t_vertex *)(map->d->content))->cons = con;

	map->e->key = "E";
	((t_vertex *)(map->e->content))->type = 0;
	con = ft_memalloc(sizeof(t_conn));
	con->current = map->d;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->b;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->f;
	con->next = NULL;
	((t_vertex *)(map->e->content))->cons = con;

	map->f->key = "F";
	((t_vertex *)(map->f->content))->type = 0;
	con = ft_memalloc(sizeof(t_conn));
	con->current = map->e;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->finish;
	con->next = NULL;
	((t_vertex *)(map->f->content))->cons = con;

	map->g->key = "G";
	((t_vertex *)(map->g->content))->type = 0;
	con = ft_memalloc(sizeof(t_conn));
	con->current = map->d;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->h;
	con->next = NULL;
	((t_vertex *)(map->g->content))->cons = con;

	map->h->key = "H";
	((t_vertex *)(map->h->content))->type = 0;
	con = ft_memalloc(sizeof(t_conn));
	con->current = map->g;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->finish;
	con->next = NULL;
	((t_vertex *)(map->h->content))->cons = con;

	map->finish->key = "FINISH";
	((t_vertex *)(map->finish->content))->type = FIN;
	con = ft_memalloc(sizeof(t_conn));
	con->current = map->f;
	con->next = ft_memalloc(sizeof(t_conn));
	con->current = map->h;
	con->next = NULL;
	((t_vertex *)(map->finish->content))->cons = con;

	return (map);
}


int main(void)
{

	t_map *map;

	map = create_map();

	return (0);
}
*/
