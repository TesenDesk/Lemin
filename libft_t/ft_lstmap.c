/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:03:13 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 16:05:28 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		delete_list(t_list **head)
{
	t_list	*prev;

	if (!*head)
		return ;
	prev = NULL;
	while ((*head)->next)
	{
		prev = (*head);
		(*head) = (*head)->next;
		free(prev->content);
		prev->content = NULL;
		free(prev);
	}
	free((*head)->content);
	(*head)->content = NULL;
	free(*head);
	*head = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*del_tmp;

	if (!lst || !f)
		return (NULL);
	if (!(tmp = f(lst)))
		return (NULL);
	del_tmp = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
		{
			delete_list(&del_tmp);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (del_tmp);
}
