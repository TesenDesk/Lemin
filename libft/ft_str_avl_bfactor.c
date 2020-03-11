/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_bfactor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:51:26 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/03 19:01:12 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_keystr_avl_bfactor(t_keystr_avl_t *p)
{
	return ((p) ? (ft_keystr_avl_height(p->left) -
			ft_keystr_avl_height(p->right)) : (0));
}
