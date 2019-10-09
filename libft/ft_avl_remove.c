/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:33:49 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:27:09 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_avl_t	*ft_avl_remove_min_p(t_avl_t *p)
{
	if (!p->left)
		return (p->right);
	p->left = ft_avl_remove_min_p(p->left);
	return (ft_avl_balance(p));
}

t_avl_t			*ft_avl_remove(t_avl_t *p, int key)
{
	t_avl_t	*left;
	t_avl_t	*right;
	t_avl_t	*min;

	if (!p)
		return (NULL);
	if (p->key < key)
		p->right = ft_avl_remove(p->right, key);
	else if (p->key > key)
		p->left = ft_avl_remove(p->left, key);
	else
	{
		left = p->left;
		right = p->right;
		free(p->content);
		free(p);
		if (!right)
			return (left);
		min = ft_avl_findmin(right);
		min->right = ft_avl_remove_min_p(right);
		min->left = left;
		return (ft_avl_balance(min));
	}
	return (ft_avl_balance(p));
}
