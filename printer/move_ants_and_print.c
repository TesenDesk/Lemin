/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants_and_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:37:04 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/05 22:46:59 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

void			print_ants_at_position(t_dlist *position, int colorize)
{
	char		*v_name;
	int			ants_name;
	static char	color[][sizeof(char *)] = {F_BL_B, F_GN_B, F_MG_B, F_CY_B,
				F_RD_B, F_YL_B, F_WT_B, F_BL_L, F_GN_L, F_MG_L, F_CY_L,
				F_RD_L, F_YL_L, F_WT_L};
	int			color_i;

	color_i = position->content_size < 14 ? position->content_size :
			position->content_size % 14;
	v_name = a_vertex((a_path(position)))->name;
	ants_name = position->flow;
	if (colorize)
		ft_putstr(color[color_i]);
	ft_putnstr("L", 1);
	ft_putnbr(ants_name);
	ft_putnstr("-", 1);
	ft_putstr(v_name);
	if (colorize)
		ft_putstr(CL);
	return ;
}

void			move_ant_forward(t_dlist *paths)
{
	t_dlist		*position;

	position = (t_dlist *)paths->content;
	position = position->next;
	paths->content = (void *)position;
	return ;
}

void			pop_up_the_ant(t_lines *properties, t_dlist **curr,
					t_dlist **head)
{
	t_dlist		*curr_after_pop;

	curr_after_pop = (*curr)->next;
	ft_ddeqextract_b(properties->moves, *curr);
	*head = properties->moves->a;
	*curr = curr_after_pop;
	return ;
}

void			move_ants_and_print(t_lines *properties)
{
	t_dlist		*curr;
	t_dlist		*head;

	head = properties->moves->a;
	curr = head;
	while (head)
	{
		if (a_vertex(a_path(curr))->type == SOURCE)
			move_ant_forward(curr);
		print_ants_at_position(curr, properties->colorize);
		if (a_vertex(a_path(curr))->type == SINK)
			pop_up_the_ant(properties, &curr, &head);
		else
		{
			move_ant_forward(curr);
			if (((curr = curr->next) == head))
				break ;
		}
		ft_putnstr(" ", 1);
	}
	ft_putnstr("\n", 1);
	return ;
}
