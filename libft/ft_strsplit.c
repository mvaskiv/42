/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:13:35 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 16:14:36 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wordsize(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static int		wordcount(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char		*strncpyy(char *dest, const char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
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
	if (!(arr = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = -1;
	while (++i < j && *s)
	{
		while (*s == c)
			s++;
		l = wordsize(s, c);
		if (!(arr[i] = malloc(sizeof(char) * (l + 1))))
		{
			free(arr);
			return (NULL);
		}
		strncpyy(arr[i], s, l);
		arr[i][l] = '\0';
		s += l;
	}
	arr[i] = NULL;
	return (arr);
}
