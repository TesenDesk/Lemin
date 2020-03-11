/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcontentdel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:56:23 by ftothmur          #+#    #+#             */
/*   Updated: 2019/09/23 15:58:26 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstcontentdel(void *content, size_t content_size)
{
	if (content && content_size)
	{
		free(content);
		(void)content_size;
	}
	return ;
}
