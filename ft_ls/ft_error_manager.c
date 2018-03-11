/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:02:59 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 19:34:15 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_flag_error(char *arg)
{
	int		i;

	i = 0;
	while (arg[i++])
	{
		if (!(ft_strchr("1alfgrRt", arg[i])))
		{
			ft_mini_printf("ft_ls: illegal option -- %c\n", arg[i]);
			ft_mini_printf("usage: ft_ls [-Raflgrt1] [file ...]\n");
			return (1);
		}
	}
	return (0);
}
