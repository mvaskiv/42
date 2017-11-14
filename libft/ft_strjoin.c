/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:04:59 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 16:05:25 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			strlenn(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (strlenn(s1) + strlenn(s2) + 1))))
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str);
}
