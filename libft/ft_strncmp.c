/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:07:38 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 16:08:13 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_strncmp(const char *s1,
	const char *s2, unsigned int n)
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
