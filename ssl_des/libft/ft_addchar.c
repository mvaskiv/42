/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:30:47 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:31:05 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_addchar(char **string, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (*string != '\0')
		i = ft_strlen(*string);
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (*string)
		ft_memmove(str, *string, i);
	ft_strdel(string);
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}
