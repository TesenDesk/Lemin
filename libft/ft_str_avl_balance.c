/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_balance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:51:10 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/03 19:01:17 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_keystr_avl_t		*ft_keystr_avl_balance(t_keystr_avl_t *p)
{
	ft_keystr_avl_fix_height(p);
	if (ft_keystr_avl_bfactor(p) < -1)
	{
		if (ft_keystr_avl_bfactor(p->right) > 0)
		{
			p->right = ft_keystr_avl_rot_right(p->right);
		}
		return (ft_keystr_avl_rot_left(p));
	}
	if (ft_keystr_avl_bfactor(p) > 1)
	{
		if (ft_keystr_avl_bfactor(p->left) < 0)
		{
			p->left = ft_keystr_avl_rot_left(p->left);
		}
		return (ft_keystr_avl_rot_right(p));
	}
	return (p);
}
