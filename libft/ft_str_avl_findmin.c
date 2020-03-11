/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_findmin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:53:05 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/03 19:01:26 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_keystr_avl_t		*ft_keystr_avl_findmin(t_keystr_avl_t *p)
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
