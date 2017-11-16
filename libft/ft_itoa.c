/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:52:23 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/16 17:17:53 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*strdupp(const char *s)
{
	int					i;
	char				*d;

	i = 0;
	while (s[i])
		i++;
	d = (char *)malloc(sizeof(char) * (i + 1));
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

static int		nbrlenn(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

char			*ft_itoa(int n)
{
	unsigned int		i;
	char				*str;
	int					t;

	i = nbrlenn(n);
	t = n;
	if (n == -2147483648)
		return (strdupp("-2147483648"));
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i] = '\0';
	while (n >= 10)
	{
		str[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	str[i - 1] = n + '0';
	return (str);
}
