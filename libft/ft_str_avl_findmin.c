/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_findmin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 22:01:14 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/08 14:06:14 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_keystr_avl_t	*ft_keystr_avl_findmin(t_keystr_avl_t *p)
{
	if (p)
	{
		if (!p->left)
			return (p);
		while (p->left)
			p = p->left;
		return (p);
	}
	return (NULL);
}
