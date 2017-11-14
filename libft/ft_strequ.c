/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:03:25 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 16:42:16 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		strcmpp(const char *s1, const char *s2)
{
	int					i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		if (s2[i] > s1[i])
			return (-1);
		i++;
	}
	return (0);
}

int				ft_strequ(char const *s1, char const *s2)
{
	if (strcmpp(s1, s2) == 0)
		return (1);
	return (0);
}
