/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:31:54 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/17 13:55:27 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_f.h"

int					ft_dlstcmp(const void *node_l, const void *node_r)
{
	return (
			ft_memcmp(
				(void *)((t_dlist *)node_l)->content,
				(void *)((t_dlist *)node_r)->content,
				((t_dlist *)node_l)->content_size));
}
