/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:56:51 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 13:02:26 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_keystr_avl_t	*ft_keystr_avl_insert(t_keystr_avl_t *p, t_pair *pair)
{
	if (!p)
		return (ft_keystr_avl_create(pair));
	if (CMP(pair->key, p->pair->key) < 0)
		p->left = ft_keystr_avl_insert(p->left, pair->key);
	else
		p->right = ft_keystr_avl_insert(p->right, pair->key);
	return (ft_keystr_avl_balance(p));
}
