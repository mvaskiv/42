/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:04:59 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/16 17:21:41 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		strlenn(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char		*strneww(unsigned int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (str[i])
		((char *)str)[i++] = (unsigned char)'\0';
	str[i] = '\0';
	return (str);
}

static char		*strdupp(const char *s)
{
	int		i;
	char	*d;

	i = 0;
	while (s[i])
		i++;
	d = (char *)malloc(sizeof(char) * i + 1);
	if (!d)
		return (0);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

static char		*strcatt(char *dest, const char *src)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!(str = strneww(strlenn(s1) + strlenn(s2) + 1)))
		return (NULL);
	str = strdupp(s1);
	strcatt(str, s2);
	return (str);
}
