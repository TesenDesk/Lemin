/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 18:40:06 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:48 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

void		do_nothing(void *nothing, size_t size)
{
	(void)nothing;
	(void)size;
}

void		*emergency_free_dlist(t_dlist *path)
{
	ft_dlstdel(&path, do_nothing);
	return (NULL);
}

int			emergency_free_dlist_return_int(t_dlist *path, int huh)
{
	ft_dlstdel(&path, do_nothing);
	return (huh);
}

void		paths_del(t_dlist *paths)
{
	t_dlist		*h;

	h = paths;
	while (TRUE)
	{
		ft_dlstdel((t_dlist **)(&paths->content), ft_delfunc_dummy);
		if ((paths = paths->next) == h)
			break ;
	}
	ft_dlstdel(&h, ft_delfunc_dummy);
}

void		*putstr_return_null(char *str)
{
	ft_putendl(str);
	return (NULL);
}
