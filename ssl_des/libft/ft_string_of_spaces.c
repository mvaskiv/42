/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_of_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:12:07 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:18:50 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_string_of_spaces(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		((char *)str)[i++] = (char)' ';
	str[i] = '\0';
	return (str);
}
