/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:10:11 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 16:41:53 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			strncmpp(const char *s1, const char *s2,
	unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == i)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] > s2[i])
			return (1);
		if (s2[i] > s1[i])
			return (-1);
		i++;
	}
	return (0);
}

int					ft_strnequ(char const *s1, char const *s2,
	unsigned int n)
{
	if (strncmpp(s1, s2, n) == 0)
		return (1);
	return (0);
}
