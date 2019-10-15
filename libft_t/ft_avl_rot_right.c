/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_rot_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 00:59:26 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:27:19 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avl_t	*ft_avl_rot_right(t_avl_t *p)
{
	t_avl_t	*tmp;

	if (!p)
		return (NULL);
	tmp = p->left;
	p->left = tmp->right;
	tmp->right = p;
	ft_avl_fix_height(p);
	ft_avl_fix_height(tmp);
	return (tmp);
}
