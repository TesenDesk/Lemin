/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_avl_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:55:19 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/03 19:02:56 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_keystr_avl_t	*ft_keystr_avl_search(t_keystr_avl_t *p, void *key)
{
	if (p)
		while (p)
		{
			if (CMP(p->pair->key, key) < 0)
				p = p->right;
			else if (CMP(p->pair->key, key) > 0)
				p = p->left;
			else
				return (p);
		}
	return (NULL);
}
