/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:54:34 by mstygg            #+#    #+#             */
/*   Updated: 2019/09/27 14:39:12 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_s;

	if (size + 1 == 0)
		return (NULL);
	if (!(new_s = (char*)malloc(size + 1)))
		return (NULL);
	ft_memset(new_s, '\0', size + 1);
	return (new_s);
}
