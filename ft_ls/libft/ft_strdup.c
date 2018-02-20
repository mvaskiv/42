/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:03:05 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 16:03:18 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strdup(const char *s)
{
	int		i;
	char	*d = NULL;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	d = (char *)malloc(sizeof(char) * i + 1);
	if (!d)
		return (0);
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			d[i] = s[i];
			i++;
		}
	}
	d[i] = '\0';
	return (d);
}
