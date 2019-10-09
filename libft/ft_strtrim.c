/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:38:38 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:40:38 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		t1;
	size_t		count;
	size_t		start;
	char		*new_s;

	if (!s)
		return (NULL);
	t1 = ft_strlen(s);
	count = 0;
	while ((*s == ' ' || *s == '\n' || *s == '\t'))
	{
		++count;
		++s;
	}
	start = count;
	s += t1 - 1 - count;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && (t1 - start))
	{
		++count;
		--s;
	}
	if (!(new_s = ft_memalloc(t1 - count + 1)))
		return (NULL);
	new_s = ft_strncpy(new_s, s - (t1 - count - 1), t1 - count);
	return (new_s);
}
