/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_bfactor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 00:15:39 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/07 22:49:19 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_keystr_avl_bfactor(t_keystr_avl_t *p)
{
	return (p) ? (ft_keystr_avl_height(p->left) - ft_keystr_avl_height(p->right)) : (0);
}
