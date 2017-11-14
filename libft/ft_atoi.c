/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:48:36 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 15:49:25 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_skip(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int				ft_atoi(const char *nptr)
{
	int		i;
	int		j;
	int		o;

	o = 0;
	i = ft_skip(nptr) + 1;
	j = i - 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		o = (o * 10) + nptr[i++] - 48;
	if (nptr[j] == '-')
		o *= -1;
	return (o);
}
