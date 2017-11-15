/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:05:33 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 16:41:32 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int			strlenn(char const *s)
{
	unsigned int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int				ft_strlcat(char *dest, char const *src,
	unsigned int n)
{
	unsigned int		i;
	unsigned int		l_d;
	unsigned int		l_s;

	i = 0;
	l_d = strlenn(dest);
	l_s = strlenn(src);
	if (n <= l_d)
		return (n + l_s);
	while (i < (n - l_d - 1) && src[i])
	{
		dest[l_d + i] = src[i];
		i++;
	}
	dest[l_d + i] = '\0';
	return (l_d + l_s);
}
