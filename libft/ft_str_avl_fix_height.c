/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_fix_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:53:19 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/03 19:00:59 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_keystr_avl_fix_height(t_keystr_avl_t *p)
{
	unsigned char	hl;
	unsigned char	hr;

	if (!p)
		return ;
	hl = ft_keystr_avl_height(p->left);
	hr = ft_keystr_avl_height(p->right);
	p->height = ((hl > hr) ? hl : hr) + 1;
	return ;
}
