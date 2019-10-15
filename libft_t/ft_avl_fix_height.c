/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_fix_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 00:18:49 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:26:50 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_avl_fix_height(t_avl_t *p)
{
	unsigned char	hl;
	unsigned char	hr;

	if (!p)
		return ;
	hl = ft_avl_height(p->left);
	hr = ft_avl_height(p->right);
	p->height = ((hl > hr) ? hl : hr) + 1;
}
