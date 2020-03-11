/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:52:52 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/03 18:59:39 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_keystr_avl_del(t_keystr_avl_t **root_incoming)
{
	t_keystr_avl_t		*root;

	root = *root_incoming;
	if (root)
	{
		if (root->left)
			ft_keystr_avl_del(&((*root_incoming)->left));
		if (root->right)
			ft_keystr_avl_del(&((*root_incoming)->right));
		free(root->pair);
		root->pair = NULL;
		free(root);
		root = NULL;
	}
	return ;
}
