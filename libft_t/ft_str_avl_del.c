/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:33:59 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/09 15:32:51 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void					ft_keystr_avl_del(t_keystr_avl_t **_root_)
{
	t_keystr_avl_t		*root;
	
	root = *_root_;
	if (root)
	{
		if (root->left)
			ft_keystr_avl_del(&((*_root_)->left));
		if (root->right)
			ft_keystr_avl_del(&((*_root_)->right));
			/*
			**free root->pair->content переделать
			*/
		if (root->pair->content)
		{
			free(root->pair->content);
			root->pair->content = NULL;
		}
		free(root->pair);
		root->pair = NULL;
		free(root);
		root = NULL;
	}
}