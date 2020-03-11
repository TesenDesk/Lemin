/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:50:48 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 14:50:49 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	For each element of the string str applies the function passed by reference.
**	Returns void.
*/

void	ft_striter(char *str, void (*fptr)(char *))
{
	if (str && fptr)
	{
		while (*str != '\0')
		{
			(*fptr)(str);
			str++;
		}
	}
	return ;
}
