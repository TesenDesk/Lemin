/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:25:11 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:25:13 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function accepts the error number, the line number of the place to call
** this function and the file name where the process that caused this error
** handling function is specified.
*/

/*
**	An auxiliary function that stores an array of error messages and, upon
** request, generates the necessary message.
**
**	It is required to ensure that the macroconstants always set the correct
** ratio between the element of the list in error and the error number.
**
**	Text format reference: https://meliorem.ru/tools/linux/kak-izmenit-cvet-\
** teksta-stroki-priglasheniya-v-terminale-linux/
*/

static char	*err_str(int error_no)
{
	char	*err_list[11];

	*(err_list + 0) = "Success";
	*(err_list + 1) = "No such file or directory";
	*(err_list + 2) = "Input/output error";
	*(err_list + 3) = "Argument list too long";
	*(err_list + 4) = "Bad file descriptor";
	*(err_list + 5) = "Cannot allocate memory";
	*(err_list + 6) = "Permission denied";
	*(err_list + 7) = "Invalid argument";
	*(err_list + 8) = "File too large";
	*(err_list + 9) = "No message of desired type";
	*(err_list + 10) = "Value too large for defined data type";
	return (*(err_list + error_no));
}

int			ft_error(int error_no, int line, char *file)
{
	char	*err_message;

	if (error_no == SUCCESS)
		return (SUCCESS);
	err_message = err_str(error_no);
	ft_putstr_fd("\e[1;31mError! \e[3;36m", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd("\e[m line ", STDERR_FILENO);
	ft_putnbr_fd(line, STDERR_FILENO);
	ft_putstr_fd(". ", STDERR_FILENO);
	ft_putendl_fd(err_message, STDERR_FILENO);
	return (FAILURE);
}
