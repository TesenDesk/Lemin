/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 23:42:54 by mstygg            #+#    #+#             */
/*   Updated: 2019/11/05 15:24:54 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ULL					hashcode(U_CHAR *str)
{
	ULL				hash;
	int				c;

	c = 0;
	hash = HASH_CONST;
	while ((c = (int)*str++))
		hash = ((hash << 5) + hash) ^ c;
	return (hash);
}

int					push_to_map(t_hash_map **map_input, t_pair *pair)
{
	ULL				index;
	t_hash_map		*map;

	map = *map_input;
	index = hashcode((U_CHAR*)pair->key) % map->arr_size;
	if (!(map->data[index] = ft_keystr_avl_insert(map->data[index], pair)))
		return (0);
	++map->map_size;
	return (1);
}

int					hm_put(t_hash_map **map, void *key, void *content)
{
	t_pair *pair;

	if (!(pair = malloc(sizeof(t_pair))))
		return (0);
	pair->key = key;
	pair->content = content;
	return (push_to_map(map, pair));
}

void				*hm_find(t_hash_map *map, void *key)
{
	ULL				index;
	t_keystr_avl_t	*avl_tmp;

	index = hashcode((U_CHAR*)key) % map->arr_size;
	if (!map->data[index])
		return (NULL);
	if (!(avl_tmp = ft_keystr_avl_search(map->data[index], key)))
		return (NULL);
	return (avl_tmp->pair->content);
}
