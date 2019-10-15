/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:19:13 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/15 23:20:27 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"

/*
** queu_destroy уничтожает очередь и высвобождает выделенную под нее память. **
*/

void queu_destroy(t_queu *q) //todo: заменить t_q на t_dl
{
	t_queu *tmp;

	if (!q)
		return ;
	while (q)
	{
		tmp = q->next;
		free(q);
		q = tmp;
	}
}

/*
** queu_add добавляет в конец очереди q заданную вершину c. **
** если очередь q не существует, создает новую. **
*/

t_queu *queu_add(t_queu *q, t_vertex *c)//todo: ect.
{
	if (q)
	{
		while (q->next)
			q = q->next;
		q->next = ft_memalloc(sizeof(t_queu));
		q = q->next;
	}
	else
		q = ft_memalloc(sizeof(t_queu));
	q->current = (t_vertex *)c;
	q->next = NULL;
	return (q);
}

/*
** add_this_q добавляет в очередь q все вершины, которые соеденены **
** с данной вершиной c и не отмеченные как посещенные. **
** если очереди не существует, создает новую. **
** возвращает указатель на голову очереди. **
*/

t_queu *add_this_q(t_vertex *c, t_queu *q)//todo: ect.
{
	t_dlist *conn;
	t_dlist *head;

	conn = c->links;
	head = conn;
	while (conn)
	{
		if (!((t_vertex *) (conn->content))->visited)
			queu_add(q, conn->content);
		conn = conn->next;
		if (conn == head)
			break ;
	}
	return (q);
}

/*
** queu_remove удаляет из головы очереди q одну вершину, **
** освобождает выделенную под нее память и возвращает оставшуюся очередь. **
*/

t_queu *queu_remove(t_queu *q) //todo:ect.
{
	t_queu	*tmp = NULL;

	if (q && q->next)
		tmp = q->next;
	free(q);
	q = 0;
	return (tmp);
}
