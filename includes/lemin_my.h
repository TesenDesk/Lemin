/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:16:46 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/17 12:17:26 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_MY_H

# define LEMIN_MY_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
#include "libft.h"
#include "libft_f.h"
#include "ft_printf.h"
#include "ftothmur.h"
#include "get_next_line.h"
#include "lemin.h"


# define START	1
# define FIN	-1
# define TRUE	1
# define FALSE	0
# define VACUUM	-1
# define LOCKED	1
# define OPEN	0

/*
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
 */
/*
typedef struct				s_queu
{
	struct s_vertex	*current;
	struct s_queu	*next;
}							t_queu;
*/

/*
typedef struct	s_conn
{
	struct s_vertex	*current;
	struct s_conn	*next;
}				t_conn;
*/


/*
** My funcs (don't forget add this in header)
*/

void				*emergency_free_dlist(t_dlist *path);
//int				ft_printf(const char *str, ...);

t_dlist *queu_add(t_dlist *q, t_vertex *c);
t_dlist *queu_remove(t_dlist *q);

t_dlist *add_this_q(t_vertex *c, t_dlist *q);
int	way_price(t_vertex *c);
t_dlist *bfs(t_vertex *c);

void unknown_func(int i);
#endif
