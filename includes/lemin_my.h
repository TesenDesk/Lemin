/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_my.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:16:46 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:29 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_MY_H

# define LEMIN_MY_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "ftothmur.h"
# include "get_next_line.h"

# define START		1
# define FIN		(-1)
# define TRUE		1
# define FALSE		0
# define VACUUM		(-1)
# define LOCKED		1
# define OPEN		0

void				*emergency_free_dlist(t_dlist *path);

void				*algorithm_run(t_graph *g);
t_dlist				*bfs(t_vertex *c);
t_vertex			*finish_found(t_vertex *c);
t_dlist				*add_another_path(t_vertex *s, t_vertex *f, t_ddeq *hub);
void				lock_path(t_dlist *path);
t_vertex			*find_cheap_vertex(t_vertex *f);
void				set_around_as_not_priced(t_vertex *f);
t_dlist				*shortest_way(t_vertex *f);
int					search_next_visited(t_vertex *c);

int					deep_bfs(t_ddeq *hub, t_vertex *s);
int					recursive_q(t_vertex *to, int i, t_vertex *from);
int					emergency_free_dlist_return_int(t_dlist *path, int huh);
t_dlist				*search_flow_parent(t_vertex *from, t_vertex *to, int i);

void				remove_visited(t_dlist *hq);
void				set_params(t_vertex *v, t_vertex *p, int i);

void				debug_print_amount_of_paths(t_dlist *paths);
void				debug_print_path(t_dlist *path);
void				debug_print_paths(t_dlist *paths, t_graph *g, int mode);
void				print_line(int c, int lng);
void				debug_print_answer_len(int len);
void				*putstr_return_null(char *str);
void				paths_del(t_dlist *paths);

t_dlist				*run_bfs(t_vertex *s, t_vertex *f, t_ddeq *hub);
t_dlist				*lets_go(t_vertex *s, t_vertex *v);
t_dlist				*deep_search_correct_path(t_vertex *f);
void				clear_all_prices(t_vertex **list, t_vertex *f);

#endif
