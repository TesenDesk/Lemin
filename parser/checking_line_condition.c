/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_line_condition.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:40:12 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 15:19:25 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					is_comment(char *str)
{
	return (*str == '#');
}

int					is_vertex(char *str)
{
	return (*str++ && ft_strchr(str, ' '));
}

int					is_dst_src(char *str)
{
	int				type;

	type = NORMAL;
	if ((*(++str) == '#' && ((type = ft_strequ(++str, "start")) ||
			ft_strequ(str, "end"))))
		return (type ? SOURCE : SINK);
	return (FALSE);
}
