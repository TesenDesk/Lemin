/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:47:38 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 18:43:08 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_keystr_avl_t	*ft_keystr_avl_create(t_pair *pair)
{
	t_keystr_avl_t	*new_tree;

	if (!(new_tree = (t_keystr_avl_t*)malloc(sizeof(t_keystr_avl_t))))
		return (NULL);
	new_tree->pair = pair;
	new_tree->left = NULL;
	new_tree->right = NULL;
	new_tree->height = 1;
	new_tree->size = 0;

	return (new_tree);
}
