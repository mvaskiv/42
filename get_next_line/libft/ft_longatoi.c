/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longatoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:53:42 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/20 16:53:55 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int				ft_skip(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

long long int			ft_longatoi(const char *nptr)
{
	int					i;
	int					j;
	long long int		o;

	o = 0;
	i = ft_skip(nptr);
	j = i;
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
		{
			o = (o * 10) + nptr[i] - 48;
			if (o > 9223372036854775807 && nptr[j] == '-')
				return (0);
			else if (o >= 9223372036854775807)
				return (-1);
		}
		else if (!((nptr[i] == '-' || nptr[i] == '+') && i == j))
			break ;
		i++;
	}
	if (nptr[j] == '-')
		o *= -1;
	return (o);
}
