/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:08:49 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/16 23:30:20 by jjerde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int					main(void)
{
	t_fill_return	a;
	
	a = fill_map();
	ft_printf("%s", (a.iserror ? "FAILURE" : "SUCCESS"));
	something(a.v_source, a.v_sink);
	return (0);
}