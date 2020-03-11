/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:52:20 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 16:21:57 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			partition(int *data, int left, int right)
{
	int				x;
	int				i;
	int				j;

	x = data[right];
	i = (left - 1);
	j = left;
	while (j <= right - 1)
	{
		if (data[j] <= x)
		{
			++i;
			ft_swap(&data[i], &data[j], sizeof(*data));
		}
		++j;
	}
	ft_swap(&data[i + 1], &data[right], sizeof(*data));
	return (i + 1);
}

void				ft_quicksort(int *data, int count)
{
	int				start_i;
	int				end_i;
	int				top;
	int				*stack;
	int				parted_i;

	start_i = 0;
	end_i = count - 1;
	top = -1;
	if (!(stack = (int *)malloc(count * sizeof(int))))
		return ;
	stack[++top] = start_i;
	stack[++top] = end_i;
	while (top >= 0)
	{
		end_i = stack[top--];
		start_i = stack[top--];
		parted_i = partition(data, start_i, end_i);
		parted_i - 1 > start_i ? stack[++top] = start_i : (void)0;
		parted_i - 1 > start_i ? stack[++top] = parted_i - 1 : (void)0;
		parted_i + 1 < end_i ? stack[++top] = parted_i + 1 : (void)0;
		parted_i + 1 < end_i ? stack[++top] = end_i : (void)0;
	}
	free(stack);
	return ;
}
