/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:11:37 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/18 17:50:26 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strnstr(char const *haystack,
	char const *needle, unsigned int n)
{
	unsigned int		l;

	if (*needle == '\0')
		return ((char *)haystack);
	l = ft_strlen(needle);
	while (*haystack && n >= l)
	{
		if (ft_strncmp(haystack, needle, l) == 0)
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}
