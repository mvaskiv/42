/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:52:23 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 17:55:28 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_itoa(int n)
{
	unsigned int		i;
	char				*str;

	i = ft_nbrlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
