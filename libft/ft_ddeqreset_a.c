/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ddeqreset_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:44:50 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/21 22:06:57 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_ddeqreset_a(t_ddeq **hub, void *content)
{
	ft_ddeqpush_b_all(*hub);
	ft_ddeq_new_a(hub, content, sizeof(void *));
	return ;
}
