/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:19:13 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/11 19:19:54 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** queu_destroy уничтожает очередь и высвобождает выделенную под нее память. **
*/

void queu_destroy(t_queu *q)
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

t_queu *queu_add(t_hash_map *map, t_queu *q, char *name)
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
	q->current = (t_vertex *)hm_find(map, name);
	q->next = NULL;
	return (q);
}

/*
** queu_remove удаляет из головы очереди q одну вершину, **
** освобождает выделенную под нее память и возвращает оставшуюся очередь. **
*/

t_queu *queu_remove(t_queu *q)
{
	t_queu	*tmp = NULL;

	if (q && q->next)
		tmp = q->next;
	free(q);
	q = 0;
	return (tmp);
}
