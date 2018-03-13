/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:06:10 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/01/25 19:27:23 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strlen(const char *s)
{
	unsigned int		i;

	i = 0;
	if (s == NULL)
		return (0);
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return ((int)i);
}
