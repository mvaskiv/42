/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:13:35 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/21 14:15:08 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		wordsize(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s != '\0' && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static int		wordcount(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c && (s[j + 1] == c || s[j + 1] == '\0'))
			i++;
		j++;
	}
	return (i);
}

static char		*strncpyy(char *dest, const char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (*src && i < n)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		l;
	char	**arr;

	j = wordcount(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	i = -1;
	while (++i < j && *s)
	{
		while (*s == c)
			s++;
		l = wordsize(s, c);
		if (!(arr[i] = (char *)malloc(sizeof(char) * (l + 1))))
		{
			ft_arrclr(arr);
			return (NULL);
		}
		strncpyy(arr[i], s, l);
		arr[i][l] = '\0';
		s += l;
	}
	arr[j] = NULL;
	return (arr);
}
