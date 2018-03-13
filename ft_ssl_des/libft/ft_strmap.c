/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:06:27 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/12/27 08:33:42 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	char				*str;
	unsigned int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (str[i])
		((char *)str)[i++] = '\0';
	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
