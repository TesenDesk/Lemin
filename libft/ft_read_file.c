/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:46:48 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:46:50 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function takes a file descriptor and a pointer, where to place the
** variable, where the file will be written, as well as the step with which to
** read.
**	The output file size limit is defined by the function ft_fit_size().
** Initially, it is equal to the maximum value of the power of two, which can be
** obtained by bitwise operations: UINT_MAX.
**	Returns the number of bytes read, or -1 if an error occurred.
*/

ssize_t	ft_read_file(int fd, char **line, ssize_t step)
{
	ssize_t			line_size;
	ssize_t			snippet;
	ssize_t			bank_size;
	int				isfit;

	line_size = 0;
	bank_size = BEST_SIZE;
	while (1)
	{
		if ((isfit = ft_fit_size(&bank_size, line_size, step)) == EOF)
			return (ERROR);
		if (!isfit || (!*line && !line_size))
			if (!(*line = (char *)ft_realloc(*line, line_size, bank_size)))
				return (ERROR);
		if ((snippet = read(fd, *line + line_size, step)) == EOF)
			return (ERROR);
		if (!snippet)
			break ;
		line_size += snippet;
	}
	if (!line_size)
		ft_memdel((void**)line);
	return (line_size);
}
