/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:18:59 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:41 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

void	debug_print_answer_len(int len)
{
	write(1, "\033[33mAnswer length: \033[1m", 24);
	ft_putnbr(len);
	write(1, "\033[0m\n", 5);
}

void	debug_print_path_len(t_dlist *paths)
{
	ft_putstr("\033[31mPath length: ");
	ft_putnbr(paths->flow);
	write(1, "\033[0m\n", 5);
}

void	debug_print_path(t_dlist *path)
{
	t_dlist		*head;
	t_vertex	*curr;

	head = path;
	while (path)
	{
		curr = path->content;
		ft_putstr(curr->name);
		path = path->next;
		if (path == head)
			break ;
		write(1, " -> ", 4);
	}
}

void	debug_print_paths_and_colors(t_dlist *paths, t_graph *g, int m, int i)
{
	static char	color[][sizeof(char *)] = {F_BL_B, F_GN_B, F_MG_B, F_CY_B,
				F_RD_B, F_YL_B, F_WT_B, F_BL_L, F_GN_L, F_MG_L, F_CY_L,
				F_RD_L, F_YL_L, F_WT_L};

	if (i >= 14)
		i %= 14;
	if (g->flags.k && (g->flags.p || g->flags.d) && m)
	{
		ft_putstr(color[i]);
	}
	write(1, "[PATH BEGIN] >>> ", 17);
	debug_print_path(paths->content);
	write(1, " <<< [END OF PATH]\n\033[0m", 23);
}

void	debug_print_paths(t_dlist *paths, t_graph *g, int mode)
{
	t_dlist		*head;
	int			i;

	if (!paths || !paths->content)
		return ;
	head = paths;
	i = 0;
	while (paths)
	{
		if ((g->flags.p && mode) || g->flags.d)
			debug_print_paths_and_colors(paths, g, mode, i++);
		if ((g->flags.l && mode) || g->flags.d)
			debug_print_path_len(paths);
		paths = paths->next;
		if (paths == head)
			break ;
	}
	if ((g->flags.p && mode) || g->flags.d)
		debug_print_amount_of_paths(paths);
	if ((g->flags.c && mode) || g->flags.d)
		debug_print_answer_len(count_answer_len(paths, g->ret.ants_count));
}
