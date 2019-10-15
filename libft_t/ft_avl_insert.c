/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:56:51 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:27:03 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avl_t	*ft_avl_insert(t_avl_t *p, int key)
{
	if (!p)
		return (ft_avl_create(key));
	if (key < p->key)
		p->left = ft_avl_insert(p->left, key);
	else
		p->right = ft_avl_insert(p->right, key);
	return (ft_avl_balance(p));
}
