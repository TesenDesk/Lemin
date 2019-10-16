/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:19:13 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/16 23:22:44 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "includes/lemin_my.h"

/*
** queu_add добавляет в конец очереди q заданную вершину c. **
** если очередь q не существует, создает новую. **
*/

t_dlist *queu_add(t_dlist *q, t_vertex *c)
{
	t_dlist *head;
	t_dlist *tmp;

	head = q;
	if (q)
	{
		if (!(tmp = ft_dlstnew(NULL, 0)))
			emergency_free_dlist(q);
		ft_dlstpush_back(&head, tmp);
	}
	else
		q = ft_dlstnew(&c, sizeof(t_vertex *));
	q->prev->content = (void *)c;
	return (q);
}

/*
** add_this_q добавляет в очередь q все вершины, которые соеденены **
** с данной вершиной c и не отмеченные как посещенные. **
** если очереди не существует, создает новую. **
** возвращает указатель на голову очереди. **
*/

t_dlist *add_this_q(t_vertex *c, t_dlist *q)
{
	t_dlist *conn;
	t_dlist *head;
	//t_dlist *tmp;

	conn = c->links;
	head = conn;
	while (conn)
	{
		if (!(((t_vertex *)(conn->content))->visited))
			queu_add(q, conn->content);
		conn = conn->next;
		if (conn == head)
			break ;
	}
	return (q);
}
