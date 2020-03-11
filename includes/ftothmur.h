/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftothmur.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:33:45 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 20:27:48 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTOTHMUR_H
# define FTOTHMUR_H

# include "libft.h"

/*
**=================================MACROSES=====================================
*/

# define READ_ERROR			(-2)

# define PARSE_ANTS			0
# define PARSE_NORMAL		1
# define PARSE_VERTEX		2
# define PARSE_EDGE			3
# define END_READ			4

# define PARSE_ERROR		0
# define FILL_ANTS			1
# define SKIP_NORM_FILL		2
# define SKIP_FOR_DSTSRC	3
# define FILL_VERTEX		4
# define CREATE_MAP			5
# define SKIP_FOR_EDGE		6
# define FILL_EDGE			7

# define SINK				(-1)
# define NORMAL				0
# define SOURCE				1

/*
**================================ARBITRARY TYPES===============================
*/

typedef struct				s_vertex
{
	char					*name;
	int						type;
	int						price;
	int						x;
	int						y;
	int						visited;
	int						cap;
	struct s_vertex			*parent;
	t_dlist					*links;
}							t_vertex;

typedef struct				s_edge
{
	char					*name_l;
	char					*name_r;
	t_vertex				*vertex_l;
	t_vertex				*vertex_r;
	t_dlist					*links_l;
	t_dlist					*links_r;
}							t_edge;

typedef struct				s_fill_return
{
	int						ants_count;
	t_vertex				*v_source;
	t_vertex				*v_sink;
	t_hash_map				*map;
}							t_fill_return;

typedef struct				s_read
{
	int						fd;
	char					*line;
	char					**lines;
	int						l_size;
	int						l_max;
	int						state;
	int						gnl;
	int						type;
}							t_read;

typedef struct				s_flag
{
	int						h;
	int						c;
	int						n;
	int						p;
	int						l;
	int						k;
	int						d;
	int						f;
	int						u;
}							t_flag;

typedef struct				s_graph
{
	t_flag					flags;
	int						params;
	t_read					reader;
	t_vertex				**vertices;
	int						v_size;
	int						max_size;
	t_edge					edge;
	t_fill_return			ret;
}							t_graph;

typedef struct				s_lines
{
	int						charge;
	int						min_len;
	t_dlist					*paths;
	t_dlist					*path_curr;
	int						prev_len_sum;
	int						flow;
	int						criterion;
	t_ddeq					*moves;
	int						initial_charge;
	int						colorize;
}							t_lines;

typedef int					(*t_parse)(t_read *);
typedef int					(*t_fill)(t_graph *);

/*
**==============================================================================
**==============================================================================
**----------------------------FUNCTION DEFINITIONS------------------------------
*/

/*
**==============================================================================
**------------------------------HEAP_MANAGEMENT---------------------------------
*/

void						free_the_project(t_lines *properties,
								t_graph *graph);

/*
**----------------------------------line----------------------------------------
*/

int							read_and_allocate_line(t_read *reader,
								t_graph *graph);

/*
**------------------------graph: map, vertices, v_names, v_links----------------
*/

void						*free_graph(t_graph *graph);

/*
**-----------------------------------map----------------------------------------
*/

int							create_map(t_hash_map **map, int v_size);
void						delete_map(t_hash_map **map);

/*
**---------------------------------vertices-------------------------------------
*/

int							initialize_graph_and_allocate_vertices(t_graph
								*graph);
int							reallocate_vertices(t_graph *graph);
void						delete_vertices(t_vertex ***vertices);
void						delete_lines(char ***lines, int l_size);

/*
**--------------------------------vertices names--------------------------------
*/

int							parse_vertices_names_and_allocate(t_graph *graph);
void						delete_auxiliary_vertices_names(char **name_l,
								char **name_r);

/*
**--------------------------------vertices links--------------------------------
*/

int							allocate_links(t_edge *edge);
void						delete_links(t_vertex **vertices, int v_size);

/*
**---------------------------------printing-------------------------------------
*/

int							push_ants_bunch_to_paths_and_move_them(
								t_lines *properties);

/*
**-----------------------------END_OF_HEAP_MANAGEMENT---------------------------
**==============================================================================
*/

/*
**==============================================================================
**----------------------------------MAIN----------------------------------------
*/

int							get_arguments_set_graph_and_properties(
								int argc, char **argv,
								t_graph *graph, t_lines *properties);
void						setup_and_run_answer_printing(t_lines *properties,
								t_graph *graph);
int							get_map_from_file(t_read *reader, char *file);
int							help_and_usage(t_flag *flags);
int							error(void);
int							catch_flags2(const char *str, t_graph *graph,
								int i);
int							catch_flags(const char *str, t_graph *graph);

/*
**---------------------------------END_OF_MAIN----------------------------------
**==============================================================================
*/

/*
**==============================================================================
**--------------------------PARSING_AND_FILLING_MANAGEMENT----------------------
*/

int							map_creation_interface(t_graph *graph);
int							parsing_input_and_map_filling_manager(t_graph
								*graph);
t_parse						*parse_dispatcher(int state);
t_fill						*map_filling_dispatcher(int state);

/*
**---------------------------------map management-------------------------------
*/

ULL							hashcode(U_CHAR *str);

t_hash_map					*create_hashmap(size_t vertices_num);
void						hm_del(t_hash_map **map);

int							push_to_map(t_hash_map **map, t_pair *pair);
int							hm_put(t_hash_map **map, void *key, void *content);
void						*hm_find(t_hash_map *map, void *key);

/*
**-----------------------------------lines--------------------------------------
*/

int							reallocate_lines(t_graph *graph);

/*
**----------------------------------parsing-------------------------------------
*/

int							parse_ants(t_read *reader);
int							parse_normal(t_read *reader);
int							rough_parse_vertex(t_read *reader);
int							rough_parse_edge(t_read *reader);

int							is_comment(char *str);
int							is_vertex(char *str);
int							is_dst_src(char *str);

/*
**----------------------------------filling-------------------------------------
*/

int							error_before_filling(t_graph *graph);
int							fill_ants(t_graph *graph);
int							skip_filling(t_graph *graph);
int							carefully_parse_then_fill_vertex(t_graph *graph);
int							skip_edge_filling(t_graph *graph);
int							fill_edge(t_graph *graph);

int							fill_nbr_field_if_possible(char *str, int len,
								int *field);
void						set_type_and_price_by_type(t_vertex *vertex,
								int *type);
void						if_unique_copy_dst_src(t_graph *graph,
								t_vertex *vertex);
int							fill_map_with_vertices(t_graph *graph);
int							create_map_fill_vertices_and_an_edge(t_graph
								*graph);
void						put_edges(t_edge *edge);
int							check_dup_edges(t_edge *edge);
int							v_cmp(const void *v_min, const void *v_sub);

/*
**-----------------------------END_OF_HEAP_MANAGEMENT---------------------------
**==============================================================================
*/

/*
**==============================================================================
**--------------------------------GRAPH_MANAGEMENT------------------------------
*/

t_vertex					*find_vertex(t_hash_map *map, char *name);
int							find_current_vertices(t_graph *graph);

/*
**-----------------------------END_OF_GRAPH_MANAGEMENT--------------------------
**==============================================================================
*/

/*
**==============================================================================
**---------------------------------ANSWER LENGTH--------------------------------
*/

int							count_answer_len(t_dlist *paths, int charge);
int							count_steps(t_lines *properties);

int							check_input_and_initialize(t_lines *properties,
								t_dlist *paths, int charge);
int							check_special_case(t_lines *properties,
								t_dlist *paths);

void						find_largest_permitted_path_its_criterion_and_flow(
								t_lines *properties);
void						determine_flow(t_lines *properties);

void						count_paths_length(t_dlist *paths);
int							calculate_criterion(t_lines *properties);
void						discharge(t_lines *properties);
int							curr_len(t_lines *properties);
int							new_len_sum(t_lines *properties);
int							is_permitted_curr_path(t_lines *properties);

t_dlist						*promote_curr_path_to_prev(t_lines *properties);
t_dlist						*promote_curr_path_to_next(t_lines *properties);
t_dlist						*first_path(t_lines *properties);

t_dlist						*next_path(t_lines *properties);
t_dlist						*prev_path(t_lines *properties);
t_dlist						*curr_path(t_lines *properties);

/*
**------------------------------END_OF_ANSWER_LENGTH----------------------------
**==============================================================================
*/

/*
**==============================================================================
**----------------------------------PRINTING------------------------------------
*/

int							print_ants_moves_manager(t_lines *properties);

t_vertex					*a_vertex(t_dlist *path);
t_dlist						*a_path(t_dlist *paths);

void						print_all_at_one_line(int charge, char *sink_name);
void						special_ants_moves(t_lines *properties, int len);
void						move_ants_and_print(t_lines *properties);

void						print_ants_moves(t_lines *properties);
void						pop_up_the_ant(t_lines *properties, t_dlist **curr,
								t_dlist **head);
void						move_ant_forward(t_dlist *paths);
void						print_ants_at_position(t_dlist *position,
								int colorize);
int							ant_name(t_lines *properties, int i);

/*
**--------------------------------END_OF_PRINTING-------------------------------
**==============================================================================
*/

#endif
