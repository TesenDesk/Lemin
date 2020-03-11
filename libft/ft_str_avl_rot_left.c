/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_rot_left.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:54:45 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/31 15:54:51 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_keystr_avl_t	*ft_keystr_avl_rot_left(t_keystr_avl_t *p)
{
	t_keystr_avl_t	*tmp;

	if (!p)
		return (NULL);
	tmp = p->right;
	p->right = tmp->left;
	tmp->left = p;
	ft_keystr_avl_fix_height(p);
	ft_keystr_avl_fix_height(tmp);
	return (tmp);
}
