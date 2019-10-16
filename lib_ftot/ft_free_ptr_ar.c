/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ptr_ar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:38:29 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/15 18:19:39 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

void				ft_free_ptr_ar(void ***ar)
{
	void			**curr;

	if (ar && (curr = *ar))
	{
		if (curr)
			while (*curr)
				free(*curr++);
		ft_memdel((void **)ar);
	}
	return ;
}
