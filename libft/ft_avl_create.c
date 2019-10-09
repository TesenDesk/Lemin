/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:47:38 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:26:39 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avl_t	*ft_avl_create(int key)
{
	t_avl_t	*new_tree;

	if (!(new_tree = (t_avl_t*)malloc(sizeof(t_avl_t))))
		return (NULL);
	new_tree->key = key;
	new_tree->left = NULL;
	new_tree->right = NULL;
	new_tree->content = NULL;
	new_tree->height = 1;
	new_tree->size = 0;
	return (new_tree);
}
