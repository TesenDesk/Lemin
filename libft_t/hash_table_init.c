/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 23:42:54 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/12 15:28:49 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

ULL      hashcode(U_CHAR *str)
{
	ULL     hash;
	int     c;

	c = 0;
	hash = HASH_CONST;
	while ((c = (int)*str++))
		hash = ((hash << 5) + hash) ^ c;
	return (hash);
}

t_hash_map			*createHashmap(size_t vertices_num)
{
	t_hash_map 		*new_map;
	size_t			i;

	i = 0;
	if (!(new_map = (t_hash_map *)malloc(sizeof(t_hash_map))))
		return (NULL);
	if (!(new_map->data = (t_keystr_avl_t **)malloc(vertices_num * sizeof(t_keystr_avl_t*))))
		return (NULL);
	while (i < vertices_num)
		new_map->data[i++] = NULL;
	new_map->arr_size = vertices_num;
	new_map->map_size = 0;
	return (new_map);
}


int					push_to_map(t_hash_map **_map_, t_pair *pair)
{
	ULL				index;
	t_hash_map		*map;

	map = *_map_;
	index = hashcode((U_CHAR*)pair->key) % map->arr_size;//нашли номер ячейки массива деревьев
	if (!(map->data[index] = ft_keystr_avl_insert(map->data[index], pair)))
		return (0);
	++map->map_size;
	return (1);
}
/*
**оберка для put
*/
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
	t_keystr_avl_t 	*avl_tmp;

	index = hashcode((U_CHAR*)key) % map->arr_size;
	if (!map->data[index])
		return (NULL);
	avl_tmp = ft_keystr_avl_search(map->data[index], key);
	return (avl_tmp->pair->content);
}

void				hm_del(t_hash_map **_map_)
{
	t_hash_map		*map;
	size_t			i;

	map = *_map_;
	i = 0;
	while (i < map->arr_size)
		ft_keystr_avl_del(&(map->data[i++]));
	free(map->data);
	map->data = NULL;
	free(map);
	*_map_ = NULL;
}
