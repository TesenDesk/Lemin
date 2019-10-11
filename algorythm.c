/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:40:48 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/11 20:33:39 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_dlist find_link(t_vertex *c, char *)
{
	t_
}

void link_destroy(t_vertex *c, t_dlist *link)
{
	t_dlist	*current = NULL;

	current = c->links;
	while (current && current->next != link)
		current = current->next;
	if (current->next == link)
		current->next = link->next;
}

void deactivate_usless_paths(t_hash_map *map)
{
	t_queu *q;
	t_vertex *c;
	t_vertex *n;

	c = hm_find(map, find_start(map)); //TODO: функция поиска истока?
	q = bfs(map, c);
	c = q->current;
	while (c)
	{
		n = hm_find(map, c->links->content);
		while (n)
		{
			if 
		}
	}

}

void first(t_hash_map *map)
{
	t_vertex *finish;

	finish = find_finish(map);
}
