/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_balance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 00:15:49 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:26:27 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avl_t	*ft_avl_balance(t_avl_t *p)
{
	ft_avl_fix_height(p);
	if (ft_avl_bfactor(p) < -1)
	{
		if (ft_avl_bfactor(p->right) > 0)
		{
			p->right = ft_avl_rot_right(p->right);
		}
		return (ft_avl_rot_left(p));
	}
	if (ft_avl_bfactor(p) > 1)
	{
		if (ft_avl_bfactor(p->left) < 0)
		{
			p->left = ft_avl_rot_left(p->left);
		}
		return (ft_avl_rot_right(p));
	}
	return (p);
}
