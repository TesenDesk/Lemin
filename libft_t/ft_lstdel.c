/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 21:30:43 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:28:54 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = NULL;
	if (!*alst || !del)
		return ;
	while ((*alst))
	{
		tmp = *alst;
		*alst = (*alst)->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
	}
}
