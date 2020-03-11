/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:48:37 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:48:39 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**______________________________
**	Name
** get_next_line -- delimited string input.
**
**	Synopsis
** #include "get_next_line.h"
** int	get_next_line(int fd, char **line);
**
**	Description
** The GNR function, when first called for a file corresponding to a given file
** descriptor, creates a copy of the contents of the file in a variable, and for
** each call to this function writes a variable in the heap, which is a series
** of characters separated from each other by a line break . Only text files are
** processed.
**
**	Return Value
** It returns 1, if there is data to read in the file, 0 if there is no more
** data in the file, and -1 in the case of error.
**______________________________
*/

/*
**	The function frees up the memory from the heap in the reverse order of
** nesting. Releases only those who have access to. Finally, deletes the node of
** the linked list from which the elements were taken to free up memory.
*/

static void			*file_free(t_list **head, t_list *node, t_file *data)
{
	if (data)
	{
		if (data->file)
			ft_memdel((void **)(&data->file));
		ft_memdel((void **)(&data));
	}
	if (head && node)
		ft_lstremove(head, node, ft_lstcmp_next);
	return (NULL);
}

/*
**	If no nodes are created, or there is no such node from the existing nodes
** that would point to the file structure with the desired file descriptor, then
** create a node and connect it to the linked list, even if it is empty. In the
** latter case, the first node of the list will be created. Then set the file
** descriptor field in accordance with the input parameter of the same name, and
** set the remaining fields to zero.
*/

static void			*file_set(int fd, t_list **head, t_list *node)
{
	t_file			*data;

	if (!(node = ft_lstnew(NULL, 0)))
		return (NULL);
	if (!(data = (t_file *)ft_realloc(NULL, 0, sizeof(t_file))))
		return (file_free(head, node, NULL));
	node->content = (void *)data;
	ft_lstadd(head, node);
	data->fd = fd;
	data->file = NULL;
	data->file_size = 0;
	data->mark = NULL;
	return (node);
}

/*
**	Assuming that the incoming parameters are a node of a linked list and a
** pointer to a file descriptor, find the nested structure field associated with
** the file descriptor by the node contents and compare it with the second
** parameter. If there is similarity return is incorrect, otherwise thei
** opposite.
*/

static int			file_cmp(const void *node_ptr, const void *fd_ptr)
{
	t_list			*node;
	t_file			*data;
	int				fd;

	node = (t_list *)node_ptr;
	data = (t_file *)(node->content);
	fd = *(int *)fd_ptr;
	return (data->fd != fd);
}

/*
**	The function returns the pointer to the node containing information
** (appropriate structure) about the file and its processing stage, according to
** the file transferred to it by the head of the associated list and file
** descriptor. Due to the fact that the GNL function works with textual data,
** and the case when a binary file arrives to process a given function is an
** object of indefinite behavior, we decided to define it in the following way:
** whether the binary file is checked, and if so, the return result is 0.
*/

static t_list		*file_get(int fd, t_list **head)
{
	t_list			*node;
	t_file			*data;

	node = *head;
	if (!node || !(node = ft_lstfind(*head, &fd, file_cmp)))
		if (!(node = file_set(fd, head, node)))
			return (NULL);
	data = (t_file *)(node->content);
	if (!data->file)
	{
		if ((data->file_size = ft_read_file(fd, &data->file, BUFF_SIZE))
					== EOF ||
				ft_isbinary(data->file, data->file_size) ||
				!(data->file = (char *)ft_realloc(data->file, data->file_size,
					data->file_size + 1)))
			return (file_free(head, node, data));
		*(data->file + data->file_size) = '\0';
		data->file_size++;
		data->mark = data->file;
		node->content = (void *)data;
	}
	return (node);
}

/*
**	The function converts the argument to correctness and operability, receives
** the prepared variable (the appropriate structure) for processing, and then
** selects exactly one line and places it in the pipe variable (created in the
** heap). By the way, if the file submitted is binary, then it is written to the
** result variable entirely, and the return value of the function is 0.
*/

int					ft_get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*node;
	t_file			*data;

	if (!line || read(fd, NULL, 0) == EOF)
		return (ERROR);
	*line = NULL;
	if (!(node = file_get(fd, &head)))
		return (ERROR);
	data = (t_file *)(node->content);
	if (!data->mark || data->file_size <= 1)
		return (((int)(file_free(&head, node, data))) || NO_MORE_LINES);
	data->mark = ft_delim(line, (char *)data->mark, '\n');
	return (ONE_MORE_LINE);
}
