/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftothmur.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:33:45 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 23:06:51 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTOTHMUR_H
# define FTOTHMUR_H

#include "libft_f.h"

#define NORMAL		0
#define WAIT_NBR	1
#define WAIT_VERTEX	2
#define WAIT_EDGE	3

#define COMMENT		1
#define VERTEX		2
#define EDGE		3

#define SINK		(-1)
#define NORMAL		0
#define SOURCE		1

typedef struct		s_vertex
{
	char			*name;
	int				type;
	int				visited;
	int 			cap;
	int				price;
	struct s_vertex	*parent;
	struct s_dlist	*links;
}					t_vertex;

typedef struct		s_edge
{
	char			*name_l;
	char			*name_r;
	t_vertex		*vertex_l;
	t_vertex		*vertex_r;
	t_dlist			*dlist_l;
	t_dlist			*dlist_r;
}					t_edge;

typedef struct		s_fill_return
{
	int				iserror;
	int				ants_count;
	char			*source;
	t_vertex		*v_source;
	char			*sink;
	t_vertex		*v_sink;
	t_hash_map		*map;
}					t_fill_return;

typedef struct		s_vertices
{
	char			*name;
	int				type;
	int				price;
	int				x;
	int				y;
}					t_vertices;

typedef struct		s_graph
{
	t_fill_return	ret;
	t_vertices		*vertices;
	int				v_size;
	int				max_size;
}					t_graph;

typedef int			(*t_parse)(t_graph *, char **);

t_vertex			*vertex_new(t_graph *graph);
t_vertex			*find_vertex(t_hash_map *map, char *name);
int					put_edges(char **linex, t_hash_map **map);
int					fill_map_with_vertices(t_graph *graph, char **line,
						int *state, t_hash_map **map);

int					iscomment(char *str);
int					try_dst_src(t_graph *graph, char **line);
int					isvertex(char *str);
int					resize_vertices(t_graph *graph, int *state);

int					is_edge(char *str);


int					parse_nbr(t_graph *graph, char **line);
int					parse_vertex(t_graph *graph, char **line);
int					parse_normal(t_graph *graph, char **line);
t_parse				*parse_dispatcher(int state);
int					parse_lines(t_graph *graph, t_hash_map **map);

t_fill_return		fill_map(void);
void				fill_vertex(t_graph *graph, char **line, int *state);
void				exit_procedure(t_graph *graph, char **line, int *state,
						t_hash_map **map);

void 				*something(t_vertex *s, t_vertex *f);

int						main(void);

#endif
