/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keystr_avl_rot_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 01:03:33 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:27:14 by mstygg           ###   ########.fr       */
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
