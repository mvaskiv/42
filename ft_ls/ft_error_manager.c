/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:02:59 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 15:02:59 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_flag_error(char *arg)
{
	int		i;

	i = 0;
	while (arg[i++])
	{
		if (!(ft_strchr("1alrRt", arg[i])))
		{
			ft_mini_printf("ft_ls: illegal option -- %c\n", arg[i]);
			ft_mini_printf("usage: ft_ls [-Ralrt1] [file ...]\n");
			return (1);
		}
	}
	return (0);
}
