/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:55:53 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:20:22 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	The function accepts a pointer to a string and a string delimiter to
** substrings. All delimiters standing in a row are considered one delimiter.
** The function creates in the heap a pointer to an array of copies of the
** found substrings created in the heap.
**	Returns a pointer to an array of substrings.
*/

static size_t	ft_tokencount(char const *str, char c)
{
	size_t		nbr;
	char const	*start;
	char const	*stop;

	if (!str)
		return (0);
	start = str;
	nbr = 0;
	while (start)
	{
		if (!(start = ft_strchr_no(start, c)))
			break ;
		nbr++;
		if (!(stop = ft_strchr(start, c)))
			break ;
		start = stop;
	}
	return (nbr);
}

static void		ft_loopstrfree(char **end, char **start)
{
	if (!end || !start)
		return ;
	if (*start == *end || *end > *start)
	{
		free(start);
		return ;
	}
	while (*start >= *end)
		free((*start)--);
	free(start);
	return ;
}

char			**ft_strsplit(char const *str, char c)
{
	char		**fshstr;
	char		**fs;
	size_t		token_nbr;
	char const	*start;
	char const	*stop;

	if (!str || !(token_nbr = ft_tokencount(str, c)) ||
			!(fshstr = (char **)malloc((token_nbr + 1) * sizeof(fshstr))))
		return (NULL);
	fs = fshstr;
	*(fs + token_nbr) = NULL;
	start = str;
	while (fs && token_nbr)
	{
		start = ft_strchr_no(start, c);
		if (!(stop = ft_strchr(start, c)))
			stop = start + ft_strlen(start);
		if (!(*fs = ft_strsub(str, start - str, stop - start)))
			ft_loopstrfree(fshstr, fs - 1);
		if (*fs++ == NULL)
			return (NULL);
		token_nbr--;
		start = stop;
	}
	return (fshstr);
}
