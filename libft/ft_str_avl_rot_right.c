/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_rot_right.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:55:05 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/31 15:55:07 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_keystr_avl_t	*ft_keystr_avl_rot_right(t_keystr_avl_t *p)
{
	t_keystr_avl_t	*tmp;

	if (!p)
		return (NULL);
	tmp = p->left;
	p->left = tmp->right;
	tmp->right = p;
	ft_keystr_avl_fix_height(p);
	ft_keystr_avl_fix_height(tmp);
	return (tmp);
}
