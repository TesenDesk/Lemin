/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstokes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:46:12 by jstokes           #+#    #+#             */
/*   Updated: 2019/10/16 23:26:44 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_mainstr
{
	t_hash_map	*map;
	t_list		*list;
	t_list		*start;
	t_list		*end;
	char		start_fl;
	char		end_fl;
	size_t		rooms;
	int			ants;

}				t_mainstr;

void			print_usage(void);
void			print_error(void);

void			clean_mainstr(t_mainstr **mainstr);
void			clean_n_error(t_mainstr *mainstr, char **mem, int fd);
void			strspl_cl_n_err(char **tmp, t_mainstr *mainstr,
							char **mem, int fd);

char			**ft_strsplitest(char const *s);
void			ft_strsplitdel(char ***arr);
void			ft_lstdelstr(t_list **alst);
void			ft_lstaddend(t_list **alst, t_list *new);
size_t			ft_lstlen(t_list *alst);

t_cont			*create_cont(int x, int y);

t_mainstr		*read_from_file(char *str);

t_mainstr		*read_from_fd(int fd);

char			**get_rooms(t_mainstr *mainstr, int fd);
void			analize_command(t_mainstr *mainstr, char **tmp, int fd);

t_mainstr		*init_mainstr(int fd);
int				check_str(char *str, int j, int num);
int				check_link(t_list *lst, char *name);

#endif
