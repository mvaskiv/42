/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:06:27 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/16 17:18:10 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	char				*str;
	unsigned int		i;

	i = 0;
	while (s[i])
		i++;
	if (!(str = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (str[i])
		((char *)str)[i++] = (unsigned char)'\0';
	str[i] = '\0';
	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
