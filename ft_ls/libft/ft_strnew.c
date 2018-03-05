/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:11:16 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/14 16:11:28 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(int size)
{
	char	*str = NULL;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
//	str = (char *)malloc(sizeof(char) * (size + 1));
	while (i <= size)
		str[i++] = '\0';
//	str[i] = '\0';
	return (str);
}
