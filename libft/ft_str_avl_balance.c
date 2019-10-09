/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_balance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:15:49 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/07 22:49:05 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_keystr_avl_t	*ft_keystr_avl_balance(t_keystr_avl_t *p)
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
