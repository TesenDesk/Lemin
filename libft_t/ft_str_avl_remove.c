/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keystr_avl_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:33:49 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:27:09 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_keystr_avl_t	*ft_keystr_avl_remove_min_p(t_keystr_avl_t *p)
{
	if (!p->left)
		return (p->right);
	p->left = ft_keystr_avl_remove_min_p(p->left);
	return (ft_keystr_avl_balance(p));
}

t_keystr_avl_t			*ft_keystr_avl_remove(t_keystr_avl_t *p, void *key)
{
	t_keystr_avl_t	*left;
	t_keystr_avl_t	*right;
	t_keystr_avl_t	*min;

	if (!p)
		return (NULL);
	// if (p->key < key)
	if (CMP(p->pair->key, key) < 0)
		p->right = ft_keystr_avl_remove(p->right, key);
	// else if (p->key > key)
	else if (CMP(p->pair->key, key) > 0)
		p->left = ft_keystr_avl_remove(p->left, key);
	else
	{
		left = p->left;
		right = p->right;
		free(p->pair->key);
		free(p->pair);
		free(p);
		if (!right)
			return (left);
		min = ft_keystr_avl_findmin(right);
		min->right = ft_keystr_avl_remove_min_p(right);
		min->left = left;
		return (ft_keystr_avl_balance(min));
	}
	return (ft_keystr_avl_balance(p));
}
