/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_fix_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 00:18:49 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/07 22:49:35 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_keystr_avl_fix_height(t_keystr_avl_t *p)
{
	unsigned char	hl;
	unsigned char	hr;

	if (!p)
		return ;
	hl = ft_keystr_avl_height(p->left);
	hr = ft_keystr_avl_height(p->right);
	p->height = ((hl > hr) ? hl : hr) + 1;
}
