/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:16:46 by jjerde            #+#    #+#             */
/*   Updated: 2019/10/11 20:41:01 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H

# define LEMIN_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
//# include "ft_printf.h"

# define START	1
# define FIN	2
# define TRUE	1
# define FALSE	2

# define BUFF_SIZE	16

typedef struct          s_dlist
{
	void				*content;
	size_t				content_size;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}                       t_dlist;

typedef	struct 				s_pair
{
	void					*key;
	void					*content;
}							t_pair;

typedef struct	s_vertex
{
	char			*name;
	int				type;
	int				visited;
	int				price;
	struct s_vertex	*parent;
	struct s_dlist	*links;
}				t_vertex;
/*
typedef struct	s_conn
{
	struct s_vertex	*current;
	struct s_conn	*next;
}				t_conn;
*/
typedef struct	s_queu
{
	struct s_vertex	*current;
	struct s_queu	*next;
}				t_queu;

//int				ft_printf(const char *str, ...);

#endif
