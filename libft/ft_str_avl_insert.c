/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:54:05 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/31 15:54:07 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_keystr_avl_t	*ft_keystr_avl_insert(t_keystr_avl_t *p, t_pair *pair)
{
	if (!p)
		return (ft_keystr_avl_create(pair));
	if (ft_strcmp(pair->key, p->pair->key) < 0)
		p->left = ft_keystr_avl_insert(p->left, pair);
	else
		p->right = ft_keystr_avl_insert(p->right, pair);
	return (ft_keystr_avl_balance(p));
}
