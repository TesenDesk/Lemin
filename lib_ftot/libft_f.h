/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_f.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:07:00 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/11 21:06:41 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_F_H
# define LIBFT_F_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>
# include <stdio.h>

// #ifndef ERROR
# define ERROR		    (-1)
// #endif
// #ifndef FAILURE
# define FAILURE	    (-1)
// #endif
// #ifndef SUCCESS
# define SUCCESS	    0
# define STDIN		    0
# define STDOUT		    1
# define STDERR		    2

// #ifndef TRUE
# define TRUE		    1
// #endif
// #ifndef FALSE
# define FALSE		    0
// #endif

#define IT_WAS_EDGE	    0
// #ifndef READ_END
# define READ_END	    0

// #endif
# define BEST_SIZE	    4096
# define LONGINTSTR_MAX	20

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_dlist
{
	void				*content;
	size_t				content_size;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}						t_dlist;

typedef long long int	t_lli;
typedef unsigned int	t_ui;

typedef struct			s_imaxdiv
{
	intmax_t			quot;
	intmax_t			rem;
}						t_imaxdiv;

typedef struct			s_uimaxdiv
{
	uintmax_t			quot;
	uintmax_t			rem;
}						t_uimaxdiv;

typedef struct			s_udiv
{
	uintmax_t			quot;
	uintmax_t			rem;
}						t_udiv;

t_dlist					*ft_dlstnew(void const *content, size_t content_size);
void					ft_dlstadd(t_dlist	**head, t_dlist *new);
void					ft_dlstaddtip(t_dlist **head, t_dlist *new);
void					ft_dlstdel(t_dlist **alst, void (*delptr)(void *,
							size_t));
void					ft_dlstcontentdel(void *content, size_t content_size);
void					ft_dlstforeach(t_dlist *node, void (*fptr)(void *));
void					ft_dlstswap(t_dlist *fst, t_dlist *snd);
t_dlist					*ft_dlstpop(t_dlist **head);
t_dlist					*ft_dlstpop_rear(t_dlist **head);
void					ft_dlstpush(t_dlist	**head, t_dlist *new);
void					ft_dlstpush_back(t_dlist **head, t_dlist *new);
t_dlist					*ft_dlstfind(t_dlist *head, void *data_ref,
							int (*cmp)(const void *min, const void *sub));
int						ft_dlstfind_i(t_dlist *head, void *data_ref,
							int (*cmp)(const void *min, const void *sub));
t_dlist					*ft_dlstfind_r(t_dlist *head, void *data_ref,
							int (*cmp)(const void *min, const void *sub));
int						ft_dlstfind_ir(t_dlist *head, void *data_ref,
							int (*cmp)(const void *min, const void *sub));
int						ft_dlstcmp(const void *node_l, const void *node_r);
int						ft_get_next_line(const int fd, char **line);
// void					ft_free_ptr_ar(void ***ar);
int						ft_isdigitstr(char *str);
int						ft_strint_ou_flow(char *str, int *nbr);
int						ft_isdigitnstr(char *str, int n);
char					*ft_imaxtostr(char *str, uintmax_t nbr,
							unsigned int base, int issign);
t_uimaxdiv				ft_uimaxdiv(uintmax_t numer, uintmax_t denom);
t_imaxdiv				ft_imaxdiv(intmax_t numer, intmax_t denom);
void					ft_lstremove(t_list **head, t_list *node,
							int (*ft_lstcmp)(t_list *, void *));
int						ft_lstcmp_next(t_list *head, void *node);
t_list					*ft_lstfind(t_list *head, void *data_ref, int (*cmp)());
char					*ft_reverse(char *buffer, int i, int j);
char					*ft_strrev(char *str);
void					ft_swap(void *x, void *y, size_t size);
void					*ft_realloc(void *buf1, size_t size1, size_t size2);

#endif
