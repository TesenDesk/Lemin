/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontentdel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:36:33 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/20 16:33:24 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcontentdel(void *content, size_t content_size)
{
	if (content && content_size)
	{
		free(content);
		(void)content_size;
	}
	return ;
}
