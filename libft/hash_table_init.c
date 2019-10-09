/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 23:42:54 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 14:39:27 by mstygg           ###   ########.fr       */
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

	if (!(new_map = (t_hash_map *)malloc(sizeof(t_hash_map))))
		return (NULL);
	if (!(new_map->data = (t_keystr_avl_t **)malloc(vertices_num * sizeof(t_keystr_avl_t*))))
		return (NULL);
	new_map->arr_size = vertices_num;
	new_map->map_size = 0;
	return (new_map);
}


int            		push_to_map(t_hash_map **map_, t_pair *pair)
{
	ULL				index;
	t_hash_map		*map;

	map = *map_;
	index = hashcode((U_CHAR*)pair->key) % map->arr_size;//нашли номер ячейки массива деревьев
	if (!(map->data[index] = ft_keystr_avl_insert(map->data[index], pair)))
		return (0);
	++map->map_size;
	return (1);
/*
**функция пока что работает с фиксированныи заранее заданным размером. здесь еще должна
**учитываться возможная пересборка
*/
}
/*
**оберка для put
*/
int					hm_put(t_hash_map **map, void *key, void *content)
{
	t_pair *pair = malloc(sizeof(t_pair));
	pair->key = key;
	pair->content = content;
	push_to_map(map, pair);
}

// int main(void)
// {
//     char *a="abc";
//     char *b="abcfds";
//     char *c="cde";
//     char *d="123";
//     char *e="def";

//     printf("%d\n", hashcode(a));
//     printf("%d\n", hashcode(b));
//     printf("%d\n", hashcode(c));
//     printf("%d\n", hashcode(d));
//     printf("%d\n", hashcode(e));
// }