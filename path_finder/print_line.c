/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjerde <jjerde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:28:06 by jjerde            #+#    #+#             */
/*   Updated: 2019/11/03 21:25:49 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_my.h"

void	print_line(int c, int lng)
{
	while (lng--)
		write(1, &c, 1);
	write(1, "\n", 1);
}
