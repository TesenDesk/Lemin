/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:33:46 by mstygg            #+#    #+#             */
/*   Updated: 2019/10/05 14:20:16 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*enlarge_str(char *str, size_t *size)
{
	char			*new_str;

	*size *= 2;
	if (!(new_str = (char*)malloc(*size)))
	{
		free(str);
		return (NULL);
	}
	new_str = ft_memcpy(new_str, str, *size / 2);
	free(str);
	return (new_str);
}

static char			*manage_str(t_avl_t *r, char *ptr, char *bf, size_t size)
{
	char			*new;
	size_t			n_s;

	n_s = r->size + 1 + ((ptr) ? (ptr - bf) : (int)(size));
	if (n_s == 1 && !ptr)
		return (NULL);
	if (!(new = ft_memjoin((char*)r->content, bf, r->size, size)))
		return (NULL);
	free(r->content);
	r->content = new;
	r->size += size;
	if (!(new = (char*)malloc(n_s * sizeof(char))))
		return (NULL);
	new = ft_memcpy(new, r->content, n_s - 1);
	*(new + n_s - 1) = '\0';
	r->size = (ptr) ? (r->size - n_s) : (0);
	r->content = (ptr) ? ft_memmove(r->content, ptr + 1, r->size) : (NULL);
	return (new);
}

static char			*m_tail(t_avl_t *r, char *ptr)
{
	size_t			n_s;
	char			*new;

	n_s = (ptr - (char*)r->content) + 1;
	if (!(new = (char*)malloc(n_s * sizeof(char))))
		return (NULL);
	new = ft_memcpy(new, r->content, n_s - 1);
	*(new + n_s - 1) = '\0';
	r->size -= n_s;
	r->content = ft_memmove(r->content, ptr + 1, r->size);
	return (new);
}

static size_t		readmepls(int fd, char **bf, char **check)
{
	size_t			count;
	ssize_t			count_read;
	size_t			ar_size;

	count = 0;
	ar_size = BUFF_SIZE;
	while ((count_read = read(fd, *bf + count, BUFF_SIZE)))
	{
		count += count_read;
		if (count == ar_size)
			if (!(*bf = enlarge_str(*bf, &ar_size)))
				return (-1);
		if ((*check = ft_memchr(*bf, '\n', count)) || count_read < BUFF_SIZE)
			break ;
	}
	return (count);
}

int					get_next_line(const int fd, char **line)
{
	static t_avl_t	*r;
	t_avl_t			*tmp;
	char			*check;
	size_t			count;
	char			*bf;

	bf = (char*)malloc(BUFF_SIZE * sizeof(char));
	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, bf, 0) < 0)
	{
		free(bf);
		return (-1);
	}
	if (!(tmp = ft_avl_search(r, fd)))
		if (!(r = ft_avl_insert(r, fd)))
			return (-1);
	tmp = ft_avl_search(r, fd);
	if ((check = ft_memchr(tmp->content, '\n', tmp->size)))
		return (!(*line = m_tail(tmp, check))) ? (-1) : (1);
	count = readmepls(fd, &bf, &check);
	if (!(*line = manage_str(tmp, check, bf, count)) && count)
		return (-1);
	free(bf);
	if (!(*line) && !count)
		r = ft_avl_remove(r, fd);
	return (!(*line) && !count) ? (0) : (1);
}
