/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:12:55 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:39:33 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	c_words(const char *s, char c)
{
	int		inside_w;
	size_t	count;

	inside_w = 0;
	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
			if (inside_w == 0)
			{
				inside_w = 1;
				++count;
			}
		if (*s == c && inside_w == 1)
			inside_w = 0;
		++s;
	}
	return (count);
}

static char		**free_arr(char ***arr)
{
	int		i;

	i = 0;
	while (*(*arr + i))
	{
		free(*(*arr + i));
		*(*arr + i++) = NULL;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	c_w;
	char	**arr;
	size_t	s_w;
	size_t	index;

	index = 0;
	c_w = c_words(s, c);
	if (!s || !c || !(arr = (char**)malloc((c_w + 1) * sizeof(char*))))
		return (NULL);
	while (c_w--)
	{
		while ((*(s + index) == c) && *(s + index))
			++index;
		s_w = index;
		while (*(s + index) != c && *(s + index))
			++index;
		if (!(*arr++ = ft_strsub(s, s_w, index - s_w)))
		{
			arr = arr - c_words(s, c) + c_w;
			return (free_arr(&arr));
		}
	}
	*arr = NULL;
	return (arr - c_words(s, c));
}
