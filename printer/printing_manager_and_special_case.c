/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_manager_and_special_case.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:36:52 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 14:37:26 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

void			print_all_at_one_line(int charge, char *sink_name)
{
	int			i;

	i = 1;
	while (i != charge)
	{
		ft_putnstr("L", 1);
		ft_putnbr(i++);
		ft_putnstr("-", 1);
		ft_putstr(sink_name);
		ft_putnstr(" ", 1);
	}
	ft_putnstr("L", 1);
	ft_putnbr(i);
	ft_putnstr("-", 1);
	ft_putendl(sink_name);
	return ;
}

void			special_ants_moves(t_lines *properties, int len)
{
	if (len == 0)
		ft_putnstr("\n", 1);
	else if (len == 1)
		print_all_at_one_line(properties->charge,
				((t_vertex *)((t_dlist *)properties->paths->content)->prev->
				content)->name);
	else
		print_ants_moves(properties);
	return ;
}

int				print_ants_moves_manager(t_lines *properties)
{
	int			len;

	if (!(properties->moves = ft_ddeqnew(NULL)) ||
			check_input_and_initialize(properties, properties->paths,
			properties->charge))
		return (FAILURE);
	if ((len = check_special_case(properties, properties->paths)) != FAILURE)
	{
		special_ants_moves(properties, len);
		return (SUCCESS);
	}
	print_ants_moves(properties);
	return (SUCCESS);
}
