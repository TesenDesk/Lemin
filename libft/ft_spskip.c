/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spskip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:48:15 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:48:16 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The function finds a pointer to the first character of the string, which
** is not whitespace, or at the end of the string, if there are no such
** characters in the string.
*/

const char	*ft_spskip(const char *str)
{
	while (isspace((int)(*str)))
		str++;
	return (str);
}
