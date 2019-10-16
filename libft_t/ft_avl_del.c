/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:42:11 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/09 14:47:15 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void					ft_avl_del(t_avl_t **_root_)
{
	t_avl_t		*root;
	
	root = *_root_;
	if (root)
	{
		if (root->left)
			ft_avl_del(&(root->left));
		if (root->right)
			ft_avl_del(&(root->right));
		if (root->content)
			free(root->content);
		root->content = NULL;
		free(root);
		root = NULL;
	}
}