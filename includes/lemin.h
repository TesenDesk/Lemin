/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:16:46 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/12 21:02:05 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H

# define LEMIN_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
//# include "ft_printf.h"

# define START	1
# define FIN	2
# define TRUE	1
# define FALSE	2
# define VACUUM	-1
# define LOCKED	1
# define OPEN	0

# define BUFF_SIZE	16

typedef struct				s_dlist
{
	void					*content;
	size_t					content_size;
	int						flow;
	struct s_dlist			*next;
	struct s_dlist			*prev;
}							t_dlist;

typedef struct				s_vertex
{
	char					*name;
	int						type;
	int						visited;
	int 					cap;
	int						price;
	struct s_vertex			*parent;
	struct s_dlist			*links;
}							t_vertex;

typedef struct				s_queu
{
	struct s_vertex	*current;
	struct s_queu	*next;
}							t_queu;

typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

typedef struct				s_avl_t
{
	int						key;
	unsigned char			height;
	void					*content;
	size_t					size;
	struct s_avl_t			*left;
	struct s_avl_t			*right;
}							t_avl_t;

typedef	struct 				s_pair
{
	char					*key;
	void					*content;
}							t_pair;

typedef struct				s_keystr_avl_t
{
	unsigned char			height;
	t_pair					*pair;
	size_t					size;
	struct s_keystr_avl_t	*left;
	struct s_keystr_avl_t	*right;
}							t_keystr_avl_t;

typedef struct				s_hashmap
{
	t_keystr_avl_t 			**data;
	size_t 					map_size;
	size_t 					arr_size;
	size_t					limit;
	size_t					l_factor;
	float					multiplier;
}							t_hash_map;

/*
typedef struct	s_conn
{
	struct s_vertex	*current;
	struct s_conn	*next;
}				t_conn;
*/
t_dlist			*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstadd(t_dlist **head, t_dlist *new);

//int				ft_printf(const char *str, ...);
/*
** queu
*/

t_queu *queu_add(t_queu *q, t_vertex *c);
t_queu *queu_remove(t_queu *q);
void queu_destroy(t_queu *q);

/*
** other
*/

t_queu *add_this_q(t_vertex *c, t_queu *q);
int	way_price(t_vertex *c);
t_queu *bfs(t_vertex *c);

#endif
