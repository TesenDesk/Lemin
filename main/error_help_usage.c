/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_help_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:49:11 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/06 16:54:37 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftothmur.h"

int						error(void)
{
	ft_putendl("ERROR");
	return (FAILURE);
}

int						help_and_usage(t_flag *flags)
{
	if (flags->h)
	{
		ft_putendl("Usage: ./lem-in -f[" BLD "hpnlkd" CL "] FILENAME "
		"or ./lem-in [" BLD "-hpnlkd" CL "] < FILENAME.\n" BLD "OPTIONS\n" CL
		"\t" BLD "-h" CL "\t\tShow this help page\n\t" BLD "-c" CL
		"\t\tShow number of steps\n\t" BLD "-n" CL "\t\tHide answer\n\t" BLD
		"-l" CL "\t\tShow paths length\n\t" BLD "-k" CL "\t\tPaint ants\n\t"
		BLD "-d" CL "\t\tDebug mode\n\t" BLD "-f <file>" CL
		"\tUse external map file\n");
		return (0);
	}
	else if (flags->u)
	{
		ft_putendl("Usage: ./lem-in -f[hpnlkd] FILENAME "
		"or ./lem-in [-hpnlkd] < FILENAME.\nUse ./lem-in -h for help.");
		return (0);
	}
	return (error());
}
