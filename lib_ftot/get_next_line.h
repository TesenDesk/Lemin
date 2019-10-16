/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:18:38 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 20:11:58 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** including system and own libraries
**		stdlib			malloc(), free()
**		unistd			read(), ssize_t
*/
# include "libft_f.h"

/*
** BUFF_SIZE for read function
** BUFF_SIZE 4096 because optimum I/O blocksize $>: stat -f %k filename
** return values of GNL:
**		FD_LIMIT		maximum fd nuber is result of "?> ulimit -Sn"
**		END_OF_LINE		heapens when '\n' or '\0', or EOF has been reached
**		ITER_DONE		no errors, but there were not an end of line
**		ERROR			error occured during execution
*/
#ifndef BUFF_SIZE
# define BUFF_SIZE		4096
#endif

# define FD_LIMIT		4864
# define NO_MORE_LINES	0
# define ONE_MORE_LINE	1

/*
** Structure synonym for input file.
*/
typedef struct	s_file
{
	int				fd;
	char			*file;
	ssize_t			file_size;
	const char		*mark;
}				t_file;

/*
** system functions. Other functions definitions or declarations with needed
** lib are in libft.h
**		malloc, free
**
** Here we need to use read(). It`s protoripe is
** ssize_t	read(int fd, void *buf, size_t count);
*/

int				get_next_line(const int fd, char **line);

#endif
