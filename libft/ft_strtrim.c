/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:15:13 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 17:49:16 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[i])
		i++;
	while (i > 0
		&& (s[i - 1] == ' ' || s[i - 1] == '\n'
		|| s[i - 1] == '\t'))
		i--;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strncpy(str, s, i);
	str[i] = '\0';
	return (str);
}
