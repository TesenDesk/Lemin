/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:08:49 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 19:53:44 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"
#include "lemin_my.h"

void					setup_and_run_answer_printing(t_lines *properties,
							t_graph *graph)
{
	properties->charge = graph->ret.ants_count;
	properties->initial_charge = properties->charge;
	properties->colorize = graph->flags.k;
	print_ants_moves_manager(properties);
	return ;
}

int						set_flags_and_fd(t_graph *graph, int argc, char **argv,
							int arg)
{
	if (argv[1][0] == '-')
	{
		if (!catch_flags(*++argv, graph))
			return (FAILURE);
		++arg;
	}
	else if (argv[1])
	{
		graph->flags.u = TRUE;
		return (FAILURE);
	}
	if (argc > arg && graph->flags.f)
	{
		if (get_map_from_file(&graph->reader, *(argv + 1)) == FAILURE)
			return (FAILURE);
	}
	else if (!graph->flags.f)
		graph->reader.fd = STDIN;
	else
		return (FAILURE);
	return (SUCCESS);
}

int						get_arguments_set_graph_and_properties(int argc,
							char **argv, t_graph *graph, t_lines *properties)
{
	int				arg;

	arg = 1;
	ft_bzero(graph, sizeof(*graph));
	if (argc > arg)
	{
		if (set_flags_and_fd(graph, argc, argv, arg) == FAILURE)
			return (FAILURE);
	}
	else
		graph->reader.fd = STDIN;
	ft_bzero((void *)properties, sizeof(*properties));
	return (SUCCESS);
}

void					print_lines(char **lines, int l_size)
{
	int					i;

	i = 0;
	while (i < l_size && (lines + i))
		ft_putendl(*(lines + i++));
	return ;
}

int						main(int argc, char **argv)
{
	t_graph				graph;
	t_lines				properties;
	int					ret;

	ret = SUCCESS;
	if (get_arguments_set_graph_and_properties(argc, argv, &graph, &properties)
			== FAILURE)
		return (help_and_usage(&graph.flags));
	if ((ret = map_creation_interface(&graph)) != FAILURE)
	{
		print_lines(graph.reader.lines, graph.reader.l_size);
		if ((properties.paths = algorithm_run(&graph)) && !graph.flags.n)
		{
			setup_and_run_answer_printing(&properties, &graph);
			if (graph.flags.c || graph.flags.d)
				debug_print_answer_len(count_answer_len(properties.paths,
					graph.ret.ants_count));
		}
	}
	free_the_project(&properties, &graph);
	return (ret == FAILURE ? error() : ret);
}
