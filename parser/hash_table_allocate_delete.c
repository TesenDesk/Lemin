/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_allocate_delete.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:58:16 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:23:29 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash_map			*create_hashmap(size_t vertices_num)
{
	t_hash_map		*new_map;
	size_t			i;

	i = 0;
	if (!(new_map = (t_hash_map *)malloc(sizeof(t_hash_map))))
		return (NULL);
	if (!(new_map->data = (t_keystr_avl_t **)malloc(vertices_num *
			sizeof(t_keystr_avl_t*))))
		return (NULL);
	while (i < vertices_num)
		new_map->data[i++] = NULL;
	new_map->arr_size = vertices_num;
	new_map->map_size = 0;
	return (new_map);
}

void				hm_del(t_hash_map **map_input)
{
	t_hash_map		*map;
	size_t			i;

	map = *map_input;
	i = 0;
	while (i < map->arr_size)
		ft_keystr_avl_del(&(map->data[i++]));
	free(map->data);
	map->data = NULL;
	free(map);
	*map_input = NULL;
	return ;
}
