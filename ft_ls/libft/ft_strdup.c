/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:03:05 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:17:30 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strdup(const char *s)
{
	int		i;
	char	*d;

	d = NULL;
	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			i++;
	}
	if (!(d = ft_strnew(i)))
		return (NULL);
	i = 0;
	if (s != NULL)
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
